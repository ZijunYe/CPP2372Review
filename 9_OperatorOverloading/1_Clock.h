
#ifndef CLOCK3_H
#define CLOCK3_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std;

class Clock {

    private:

        long seconds;

    public:

        Clock(long sec=0) : seconds(sec) { }
        Clock(int d, int hrs, int min, long sec) {
                seconds= sec + min*60 + hrs*3600 + d*86400; }
        Clock(const Clock &t) : seconds(t.seconds) { }

        long sec() const {return seconds%60;}
        int min() const {return (seconds/60)%60;}
        int hr()  const {return (seconds/3600)%24;}
        int day() const {return seconds/86400;}



        // a += b is equivalent to a.operator+=(b);
        // operator : keyword when redefining operators
        // binary : 2 operands *this and right
        Clock& operator+=(const Clock &right) {
                seconds+= right.seconds;
                // return the result by reference
                return *this; }

        Clock& operator-=(const Clock &right) {
                seconds-= right.seconds; return *this; }

        // a =~ b is equivalent to a= b.operator~();
        // unary: 1 operands *this
        // const so does not change the state of the object
        const Clock operator~() const {
                Clock t(*this);
                if (t.sec()<30) t.seconds-= t.sec();
                else t.seconds+= 60-t.sec();
                return t; }

       // pre-increment
        // int differentiates post and pre-increment,
        Clock& operator++() { *this+= 1; return *this; }

        // post-increment
        // const to avoid calling a non-const method/fct
        const Clock operator++(int) { // int => dummy operand
                Clock tk(*this);
                ++(*this);
                // return the result by value
                return tk;
                // option alternative: return Clock(seconds++);
            }

        const string toString() const {
            stringstream ss (stringstream::in | stringstream::out);
            ss << day() << "day" << (day()>1?"s ":" ");
            ss << hr() << "hr" << (hr()>1?"s ":" ");
            ss << min() << "min" << (min()>1?"s ":" ");
            ss << sec() << "sec";
            return ss.str();}
};

// cout is an output stream
// so we use an ostream
    inline ostream&
operator<<(ostream &left, const Clock &right) { // function

        left << right.toString();
        return left;
         // important to return the ostream to chain couts
    }

// implicit conversion from int to Clock
const Clock operator+
                (const Clock &left, const Clock &right);
const Clock operator-
                (const Clock &left, const Clock &right);


#endif // CLOCK3_H