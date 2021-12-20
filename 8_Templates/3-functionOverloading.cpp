

#include <iostream>
#include "3-fraction.h"

using namespace std;

/*--------------------------------------------------------*\
Function calling rules (determined at compile time)
    1. Exact match
    2. Trivial match
        array name -> pointer
        int -> const int
    3. A template function
    4. Match with promotion
        char -> int
        short -> int
        float -> double
    5. Match with standard conversion
        int -> float
        float -> int
        Derived* -> Base*
        T* -> void
    6. Match with conversion defined by the use of
        one argument constructor


\*-------------------------------------------------------*/

void fct(char) {
    cout << "fct(char) called" << endl;
}

void fct(double) {
    cout << "fct(double) called" << endl;
}

void fct(int, float) {
    cout << "fct(int, float) called" << endl;
}

void fct(int, double) {
    cout << "fct(int, double) called" << endl;
}

void add(Fraction &f, long l) {
    cout << "add(Fraction &f, long l) called" << endl;
}

void add(long l, Fraction &f) {
    cout << "add(long l, Fraction &f) called" << endl;
}

void add(Fraction &f1, Fraction &f2) {
    cout << "add(Fraction &f1, Fraction &f2) called" << endl;
}

int main()
{
     // fct(1);
    // -> compilation error:
    // ambiguity between fct(double) and fct(char)
    
    fct(9.9); // exact match

    double d = 2.0;
    char x = 2;

    fct(x, d);
    // arg1 -> fct(int, float) or fct(int, double)
    // arg2 -> fct(int, double)
    // fct(int, double) is the intersection between the two

    //fct(x, x);
    // arg1 -> fct(int, float) or fct(int, double)
    // arg2 -> fct(int, float) or fct(int, double)
    // -> compilation error: ambiguity

    // Note: For the next conversions, a
    // conversion is defined from long to fraction

    Fraction f(2, 3);
    add(f, 23);
    // arg1 -> add(Fraction, long) or add(Fraction, Fraction)
    // arg2 -> add(Fraction, long)
    // add(Fraction, long) is the intersection between the two

    // add(21, 23);
    // arg1 -> add(long, Fraction)
    // arg2 -> add(Fraction, long)
    // -> compilation error: no match found


    /*----------------- result ----------------------*\
    fct(double) called
    fct(int, double) called
    add(Fraction &f, long l) called
    \*-------------------------------------------------*/



}