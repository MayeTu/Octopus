#include "basa.hpp"

using namespace std;

    void Basa::load (ifstream& file)
    {
        item temp;
        while (file>>temp)
        {
            items.pushback(temp);
        }
    }
    void Basa::unload(ofstream& file)
    {
        for (int i=0; i<items.getsize(); i++)
        {
            file << items[i] << endl;
        }
    }
    void Basa::work()
    {
        cout << "  WELCOME TO PERFUME STORE" << endl;
        char num=0;
        char musor;
        while (num!='9')
        {
            cout << endl;
            cout << "      Main Menu\n";
            cout << "1) view all products \n";
            cout << "2) show all products by name \n";
            cout << "3) show all products by price \n";
            cout << "4) show all products by brand \n";
            cout << "5) add product \n";
            cout << "6) delete product \n";
            cout << "7) edit product \n";
            cout << "8) delete all products \n";
            cout << "9) exit \n";
            cout << "\n";
            cout << ">";

            cin >> num;
            switch (num)
            {
            case '1':
                for (int i=0; i<items.getsize(); i++)
                {
                    cout << items[i] << endl;
                }
                break;
            case '2':
            {
                int k=0;
                string str;
                cout << "enter name \n";
                cin >> str;
                for (int i=0; i<items.getsize(); i++)
                {
                    if (str==items[i].getname())
                    {
                        cout << items[i] << endl;
                        k++;
                    }
                }
                if (k==0)
                {
                    cout << "   there is no such products \n";
                }
            }
            break;
            case '3':
            {
                int k=0;
                int pr;
                cout << "enter price \n";
                cin >> pr;
                for (int i=0; i<items.getsize(); i++)
                {
                    if (pr==items[i].getprice())
                    {
                        cout << items[i] << endl;
                        k++;
                    }
                }
                if (k==0)
                {
                    cout << "   there is no such products \n";
                }
            }
            break;
            case '4':
            {
                int k=0;
                string br;
                cout << "enter brand \n";
                cin >> br;
                for (int i=0; i<items.getsize(); i++)
                {
                    if (br==items[i].getbrand())
                    {
                        cout << items[i] << endl;
                        k++;
                    }
                }
                if (k==0)
                {
                    cout << "   there is no such products \n";
                }
            }
            break;
            case '5':
            {
                cout << "   enter name, brand and price\n";
                item t;
                cin >> t;
                items.pushback(t);
            }
            break;
            case '6':
            {
                cout << "   enter name, brand and price\n";
                item t;
                cin >> t;
                int k=0;
                for (int i=0; i<items.getsize(); i++)
                {
                    if (items[i]==t)
                    {
                        items.removeByIndex(i);
                        k=1;
                        break;
                    }
                }
                if (k==0)
                {
                    cout << "   there is no such products \n";
                }
            }
            break;
            case '7':
            {
                cout << "   enter name, brand and price of product you want to change\n";
                item t;
                cin >> t;
                int k=-1;
                for (int i=0; i<items.getsize(); i++)
                {
                    if (items[i]==t)
                    {
                        k=i;
                        break;
                    }
                }
                if (k==-1)
                {
                    cout << "   there is no such products \n";
                }
                else
                {
                    cout << "   enter new name, brand and price of product \n ";
                    cin >> items[k];
                }
            }
            break;
            case '8':
		cout << "   are you sure you want to delete all data? \n";
		cout << "   enter Y to confirm \n";
		char a;
		cin >> a;
		if (a=='y'){
                	for (int i=items.getsize()-1; i>=0; i--)
                	{
                    		items.removeByIndex(i);
                	}
		}
                break;
            case '9':
                break;
            default:
                cout << "please choose correct number" << endl;
            }
        }
    }
