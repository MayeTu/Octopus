#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class item
{
private:
    string name;
    string brand;
    int price;
public:
    string getname()
    {
        return name;
    }
    string getbrand()
    {
        return brand;
    }
    int getprice()
    {
        return price;
    }
    void setname(string newname)
    {
        name=newname;
    }
    void setbrand(string newbrand)
    {
        brand=newbrand;
    }
    void setprice(int newprice)
    {
        price=newprice;
    }
    friend ostream& operator<< (ostream &out, const item &it)
    {
        out << it.name << "   " << it.brand << "   " <<it.price;
        return out;
    }
    friend istream& operator>> (istream &in, item &it)
    {
        in >> it.name;
        in >> it.brand;
        in >> it.price;
        return in;
    }
};

class Vector
{
private:
    item* items;
    int Size;
    int capacity;
public:
    Vector()
    {
        Size=0;
        capacity=5;
        items=new item[capacity];
    }
    void pushback(item newitem)
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
    item operator[] (int i)
    {
        if (i<Size)
        {
            return items[i];
        }
        else
        {
            exit(0);
        }
    }
};

class Basa
{
private:
    Vector items;

public:
    void load (ifstream& file){
        item temp;
        while (file>>temp){
            items.pushback(temp);
            cout << temp << endl;
        }
        ///cout << items[2];
    }
};

int main(int argc, char** argv)
{
    /*item a;
    cin >> a;
    cout << endl << a;*/
    if (argc!= 2)
    {
        cout << "   !!!  provide exactly 1 database filename  !!!   " << endl;
        return 0;
    }
    string filename=argv[1];
    ifstream file;
    file.open(filename);
    if (!file.is_open())
    {
        cout << "   !!!  no such file  !!!   " << endl;
        return 0;
    }

    //Basa basa;
    //basa.load(file);

    return 0;
}
