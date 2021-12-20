
#include <iostream>
#include <stdlib.h>
#include "3-Clock.h"

Clock horloge1(60);

    void
fonction1() {

    cout << "function1() starts here" << endl;

    static Clock clocks(240);
    Clock clock(300);

    cout << "end of function1()" << endl;
}

    Clock
fonction2(Clock clock) {

    cout << "function2() starts here" << endl;
    clock++;
    Clock watch(360);
    cout << "end of function2()" << endl;

    return Clock(watch + 60);
}


int main() {

    cout << "main() starts here" << endl;

    Clock horloge2(120);

    cout << "call fonction1()" << endl;
    fonction1();
    cout << "return to main()" << endl;
    cout << "call fonction1()" << endl;
    fonction1();
    cout << "return to main()" << endl;

    Clock clock3(180);

    cout << "call fonction2()" << endl;
    clock3= fonction2(horloge2)+clock3;
    cout << "return to main()" << endl;

    cout << "end of main()" << endl;
}

/*--------------- resutls ---------------*\


-> constructor of 0day 0hr 2mins 0sec
call fonction1()
function1() starts here
-> constructor of 0day 0hr 4mins 0sec
-> constructor of 0day 0hr 5mins 0sec
end of function1()
-> destructor of 0day 0hr 5mins 0sec
return to main()
call fonction1()
function1() starts here
-> constructor of 0day 0hr 5mins 0sec
end of function1()
-> destructor of 0day 0hr 5mins 0sec
return to main()
-> constructor of 0day 0hr 3mins 0sec
call fonction2()
-> copy constructor with 0day 0hr 2mins 0sec
function2() starts here
-> copy constructor with 0day 0hr 2mins 0sec
-> destructor of 0day 0hr 2mins 0sec
-> constructor of 0day 0hr 6mins 0sec
end of function2()
-> conversion to integer360
-> constructor of 0day 0hr 7mins 0sec
-> destructor of 0day 0hr 6mins 0sec
operator+ 0day 0hr 7mins 0sec 0day 0hr 3mins 0sec
-> copy constructor with 0day 0hr 7mins 0sec
-> copy constructor with 0day 0hr 10mins 0sec


\*--------------------------------------*/

