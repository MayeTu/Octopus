#include "item.hpp"

class Vector
{
private:
    item* items;
    int Size;
    int capacity;
public:
    Vector();
    void pushback(item newitem);
    item& operator[] (int i);
    int getsize();
    ~Vector();
    void removeByIndex(int j);
};

