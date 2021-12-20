
#ifndef CLOCK5_H
#define CLOCK5_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

class Clock {

    private:

        long seconds;

    public:

        explicit Clock(long sec=0);
        Clock(int j, int hrs, int min, long sec);
        Clock(const Clock &t);
        ~Clock();

        long sec() const {return seconds%60;}
        int min() const {return (seconds/60)%60;}
        int hr()  const {return (seconds/3600)%24;}
        int day() const {return seconds/86400;}

        Clock& operator=(const Clock& h);
        Clock& operator=(long t) {
            seconds= t; return *this;
        }

        Clock& operator+=(const Clock &right) {
                seconds+= right.seconds; return *this; }
        Clock& operator-=(const Clock &right) {
                seconds-= right.seconds; return *this; }
        const Clock operator~() const {
                Clock t(*this);
                if (t.sec()<30) t.seconds-= t.sec();
                else t.seconds+= 60-t.sec(); return t; }
        Clock& operator++() { seconds++; return *this; }
        const Clock operator++(int) {
                Clock tk(*this); ++(*this);
                return tk; }

        const string toString() const {
            stringstream ss (stringstream::in
                                      | stringstream::out);
            ss << day() << "day" << (day()>1?"s ":" ");
            ss << hr() << "hr" << (hr()>1?"s ":" ");
            ss << min() << "min" << (min()>1?"s ":" ");
            ss << sec() << "sec";
            return ss.str();}

        operator int() const;
        
        friend ostream& operator<<(const ostream &left,
                                   const Clock &right);
};

    inline ostream&
operator<<(ostream &left, const Clock &right) {

        left << right.toString();
        return left;
}



const Clock operator+(const Clock &left,
                                    const Clock &right);
const Clock operator-(const Clock &left,
                                    const Clock &right);

#endif // CLOCK5_H