
#include "4-Bag.h"
#include "4-Clock.h"
#include <iostream>
#include <stdlib.h>

int main() {

    Bag<int> c;
    Bag<Clock,8> b1(4), b2;

    c+= 1;
    c+= 2;
    c+= 3;
    c+= 4;
    cout << "a) " << *c << " and " << *c << endl;

    Clock h1(16,2,4,0);
    Clock h2(5,22,56,0);
    Clock h3(7,15,8,0);
    Clock h4(19,7,14,0);
    Clock h5(55,9,5,0);
    Clock h6(1,21,22,0);

    b1+= h1;
    b1+= h2;
    b1+= h3;
    b1+= h4;
    b1+= h5;
    b1+= h6;

    b2 = b1;

    cout << "b) " << b1.getCapacity() << endl;
    cout << "c) " << *b1 << endl;
    cout << "d) " << *b1 << endl;
    cout << "e) " << *b1 << endl;
    cout << "f) " << *b1 << endl;

    cout << "g) " << *b2 << endl;

    cout << "h) " << b1.getSize() << " and "
                            << b2.getSize() << endl;

    b1 += b2;

    cout << "i) " << b1.getSize() << endl;
    
    return 0;
}

/*--------------- results ---------------*\

a) 4 and 2
b) 8
c) 16days 2hrs 4mins 0sec
d) 55days 9hrs 5mins 0sec
e) 1day 21hrs 22mins 0sec
f) 7days 15hrs 8mins 0sec
g) 1day 21hrs 22mins 0sec
h) 2 and 5
i) 7

\*--------------------------------------*/