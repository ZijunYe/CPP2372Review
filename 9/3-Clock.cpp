
#include "3-Clock.h"

    Clock::
Clock(long sec) : seconds(sec) {

    cout << "-> constructor of " << *this << endl;
}

    Clock::
Clock(int j, int hrs, int min, long sec) {

    seconds= sec + min*60 + hrs*3600 + j*86400;
}

    Clock::
Clock(const Clock &t) : seconds(t.seconds) {

    cout << "-> copy constructor with " << t << endl;
}

    Clock::
~Clock() {

    cout << "-> destructor of " << *this << endl;
}
    
    Clock& 
Clock::operator=(const Clock& h) {

    cout << "-> operator=  " << h << endl;
    if (this!=&h) 
        seconds= h.seconds;
        
    return *this;
}

    Clock::
operator int() const { 
    cout << "-> conversion to integer" << seconds << endl; 
    return seconds; 
}


    const Clock
operator+(const Clock &left, const Clock &right) {

    cout << "operator+ " << left << " " << right << endl; 
    return Clock(left) += right;
}

    const Clock
operator-(const Clock &left, const Clock &right) {

    return Clock(left) -= right;
}