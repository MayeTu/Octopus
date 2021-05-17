#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class item
{
private:
    string name;
    string brand;
    int price;
public:
    string getname();
    string getbrand();
    int getprice();
    void setname(string newname);
    void setbrand(string newbrand);
    void setprice(int newprice);
    friend ostream& operator<< (ostream &out, const item &it);
    friend istream& operator>> (istream &in, item &it);
    bool operator== (item& r);
};

