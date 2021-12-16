
#include <iostream>
#include <stdlib.h>
#include "2-Clock.h"

    int main() {

        Clock t1(2,1,45,30);
        Clock t2(516473);
        Clock t3;

        cout << "a) " << t1 << endl;
        cout << "b) " << t2 << endl;

        t3= t1 + t2;
        cout << "c) " << t3 << endl;

          // operator int 516473- 25
        // if we remove "explicit" this becomes ambiguous
        t3= t2 - 25;
        // t3.operator=(operator-(operator int(t2), 25))
        cout << "d) " << t3 << endl;

         // explicit conversion is still allowed
        t3+= static_cast<Clock>(25);
        cout << "e) " << t3 << endl;

        int t;
        // (operator-(t2,t1).operator int)
        t= t2 - t1;
        cout << "f) " << t << endl;

        return 0;
}

/*--------------- results ---------------*\
a) 2days 1hr 45mins 30sec
b) 5days 23hrs 27mins 53sec
c) 8days 1hr 13mins 23sec
d) 5days 23hrs 27mins 28sec
e) 5days 23hrs 27mins 53sec
f) 337343


\*--------------------------------------*/

