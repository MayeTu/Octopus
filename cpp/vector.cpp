#include "vector.hpp"

using namespace std;

    Vector::Vector()
    {
        Size=0;
        capacity=5;
        items=new item[capacity];
    }
    void Vector::pushback(item newitem)
    {
        if (Size==capacity)
        {
            item* temp= new item[Size+ capacity];
            for (int i=0; i<Size; i++)
            {
                temp[i]=items[i];
            }
            swap(items,temp);
            delete[] temp;
            capacity+=Size;

        }
        items[Size]=newitem;
        Size++;
    }
    item& Vector::operator[] (int i)
    {
        if ((i<Size) && (i>=0))
        {
            return items[i];
        }
        else
        {
            exit(0);
        }
    }
    int Vector::getsize()
    {
        return Size;
    }
    Vector::~Vector()
    {
        delete[] items;
        items=nullptr;
    }
    void Vector::removeByIndex(int j)
    {
        if ((j<Size) && (j>=0))
        {
            Size--;
            for (int i=j; i<Size; i++)
            {
                items[j]=items[j+1];
            }
        }
    }

