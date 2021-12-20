
#define PI 3.1416
#define MIN1(a, b) (a < b) ? a : b
#define MIN2(a, b) (((a) < (b)) ? (a) : (b))
#define Rounding(x) (static_cast<int>((x) + 0.5))
#include <iostream>

using namespace std;

int main()
{
    int a=3, b = 4;
    int z;
    
    int c = (a > b) ? 8 : 7; //If true 8, otherwise 7

    z = MIN1(a*2, b +5);
    cout << "z = " << z << endl;

    int x = 2, y = 3;
    z = MIN1(x, y) + 7; // NO!
    cout << "z = " << z << endl;

    z = MIN2(x, y) + 7; // NO!
    cout << "z = " << z << endl;
    
    double v = 5.4;
    cout << "v = " << Rounding(v) << endl;

    double w = 5.6;
    cout << "w = " << Rounding(w) << endl;

    /*----------------- result ----------------------*\
    z = 6
    z = 2
    z = 9
    v = 5
    w = 6
    \*-------------------------------------------------*/

}
