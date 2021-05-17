#include "item.hpp"

using namespace std;

    string item::getname()
    {
        return name;
    }
    string item::getbrand()
    {
        return brand;
    }
    int item::getprice()
    {
        return price;
    }
    void item::setname(string newname)
    {
        name=newname;
    }
    void item::setbrand(string newbrand)
    {
        brand=newbrand;
    }
    void item::setprice(int newprice)
    {
        price=newprice;
    }
    ostream& operator<< (ostream &out, const item &it)
    {
        out << it.name << "   " << it.brand << "   " <<it.price;
        return out;
    }
    istream& operator>> (istream &in, item &it)
    {
        in >> it.name;
        in >> it.brand;
        in >> it.price;
        return in;
    }
    bool item::operator== (item& r)
    {
        if ((name==r.name)&&(brand==r.brand)&&(price==r.price))
        {
            return true;
        }
        else
        {
            return false;
        }
    }


