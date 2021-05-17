#include <iostream>

using namespace std;

template <typename T>
class Fraction{
    private:
        T up, down;
    public:
        Fraction( T up,  T down):up(up), down(down){
           int znak=1;
           if ((up*down)<0){
              znak=-1;
           }
           up=abs(up);
           down=abs(down);
           T nod=1;
           for (T cnod=2;cnod<min(up,down);cnod++){
                if ((up % cnod == 0) && (down % cnod == 0)){
                    nod = cnod;
                }
           }
           this->up=znak*(up/nod);
           this->down=down/nod;
        }
        Fraction operator+(const Fraction& right){
            return Fraction( up * right.down + right.up * down, down * right.down );
        }
        Fraction operator-(const Fraction& right){
            return Fraction( up * right.down - right.up * down, down * right.down );
        }
        Fraction operator*(const Fraction& right){
            return Fraction( up * right.up, down * right.down);
        }
        bool operator==(const Fraction& right){
            return up==right.up && down == right.down;
        }
        friend ostream& operator<<(ostream& out, const Fraction& frac){
            if (frac.up == 0){
                out << 0;
            }
            else {
                if (frac.up == frac.down){
                    out << 1;
                }
                else {
                    if (frac.up % frac.down ==0){
                        out << frac.up / frac.down ;
                    }
                    else {
                        out << frac.up <<  "/" << frac.down;
                    }
                }
            }
            return out;
        }
};

int main(){
	cout << "enter the numerators and denominators of fractions: A and B" << endl;
	int a1,b1,a2,b2;
	cin >> a1 >> b1 >> a2 >> b2;	//for int
	Fraction<int> a(a1,b1),b(a2,b2);

	/*char a1,b1,a2,b2;
	cin >> a1 >> b1 >> a2 >> b2;    //for char
	Fraction<char> a(a1,b1),b(a2,b2);*/

	cout << "A=" << a1 << "/" << b1 << endl;
	cout << "B=" << a2 << "/" << b2 << endl;
	cout << "A+B=" << a+b << endl;
	cout << "A*B=" << a*b << endl;
	cout << "A-B=" << a-b << endl;
	if (a==b){
        cout << "A=B" << endl;
	}
	else {
        cout << "A!=B" << endl;
	}
	return 0;
}
