
#include "2-Bag.h"
#include <iostream>
#include <stdlib.h>

Bag<int> getNumberofBags(int n) {
    
    Bag<int> b;
    
    for (int i=0; i<n; i++)
        b+= i;
        
    return b;
}

int main() {

    Bag<int> c(10); //calls line 38 of 2-Bag.h
    c+= 1;//calls line 103 of 2-Bag.h
    c+= 2;
    c+= 3;
    c+= 4;
    cout << "i) " << *c << " and " << *c << endl; //calls line 127 of 2-Bag.h (two times!)

    c= getNumberofBags(1000); //when returning from this function it calls line 48 and then 58 of 2-Bag.h
    cout << "ii) " << *c << " and " << *c << endl;
    
    Bag<int> d;
    d=c;
    cout << "iii) " << *d << " and " << *d << endl;
    cout << d.getCapacity() << " and " << c.getCapacity() << endl;

    Bag<int> e;
    e=std::move(d); // calls line 66 of 2-Bag.h 
	//Remember that in the above statement, we do not intend to use --d-- again except to assign to it or to destroy it.
    cout << "iv) " << *e << " and " << *e << endl;
    cout << d.getCapacity() << " and " << e.getCapacity() << endl;

    return 0;
}

/*--------------- results ---------------*\

i) 4 and 1
move assignment
Destructor of the bag with capacity 10
ii) 821 and 527
assignment
iii) 553 and 43
1024 and 1024
move assignment
iv) 383 and 217
64 and 1024
Destructor of the bag with capacity 1024
Destructor of the bag with capacity 64
Destructor of the bag with capacity 1024


\*--------------------------------------*/
