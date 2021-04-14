#include <iostream>
#include <fstream>
#include <string>
#include "basa.hpp"

using namespace std;


int main(int argc, char** argv)
{
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
    Basa basa;
    basa.load(file);
    file.close();

    basa.work();

    ofstream fille;
    fille.open(filename);
    if (!fille.is_open())
    {
        cout << "   !!!  no such file  !!!   " << endl;
        return 0;
    }
    basa.unload(fille);
    fille.close();


    return 0;
}

