
#include <iostream>
#include <stdlib.h>
#include "1_Clock.h"

int main() {

        Clock t1(2,1,45,30);
        Clock t2;
        Clock t3;

        t2= 43482;
        cout << t1 <<  " and " << t2 << endl;

        t1+= t2;
        cout << "a) " << t1 << endl;

        t3= t1 + t2;
        cout << "b) " << t3 << endl;

        t3= t2 - 25; // 25 is interpreted as seconds
        cout << "c) " << t3 << endl;

         // only works because the
        // operator is defined using a
        t3= 10 + t1;
        cout << "d) " << t3 << endl;

        t1= ++t3 + 60;
        cout << "e) " << t1 << endl;

        t3= t1++;
        cout << "f) " << t3 << endl;
        cout << "g) " << t1 << endl;

        cout << "h) " << ~t2 << endl;

        return 0;
}

/*--------------- results ---------------*\

2days 1hr 45mins 30sec and 0day 12hrs 4mins 42sec
a) 2days 13hrs 50mins 12sec
b) 3days 1hr 54mins 54sec
c) 0day 12hrs 4mins 17sec
d) 2days 13hrs 50mins 22sec
e) 2days 13hrs 51mins 23sec
f) 2days 13hrs 51mins 23sec
g) 2days 13hrs 51mins 24sec
h) 0day 12hrs 5mins 0sec


\*--------------------------------------*/

