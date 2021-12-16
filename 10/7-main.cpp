
#include <iostream>
#include <set>
#include <stdarg.h>
#include "7-employee.h"

using namespace std;


bool operator<(Employee a, Employee b) {
    if (a.getName().compare(b.getName()) == 0)
        return a.getFirstname().compare(b.getFirstname()) < 0;
    else
        return a.getName().compare(b.getName()) < 0;
}

int main()
{
    // Associative container that stores its elements
    // in order.  The elements themselves serve as a key.
    set<Employee> se;
    se.insert(Employee("Joe", "Tremblay"));
    se.insert(Employee("Real", "Tremblay"));
    se.insert(Employee("Stephane", "Lacroix"));
    se.insert(Employee("Joel", "Lamirand"));

    cout << "The set contains the following employees : ";
    cout << endl;
    for (set<Employee>::iterator it2 = se.begin();
                                        it2 != se.end(); it2++) {
        Employee e = *it2;
        cout << e.getFirstname() << " " << e.getName() <<  endl;
    }

     // An employee is found in the set
    // !(a<b or b<a) => equivalence
    Employee bidon("Joe", "Tremblay");
    set<Employee>::iterator it = se.find(bidon);

    // The employee pointed by the iterator is replaced by a
    // new employee.
    if (it != se.end()) {
        Employee tmp(*it);
        tmp.setFirstname("Joel");
        se.erase(it);
        se.insert(tmp);
    }

    // the emplace method (call to the constructor)
    se.emplace("Bouchard");

    cout << endl;
    cout << "The set now contains the following employees: ";
    cout << endl;
    for (set<Employee>::iterator it2 = se.begin();
                                        it2 != se.end(); it2++) {
        Employee e = *it2;
        cout << e.getFirstname() << " " << e.getName() <<  endl;
    }
}

/*--------------------- results -------------------------*\
The set contains the following employees :
Stephane Lacroix
Joel Lamirand
Joe Tremblay
Real Tremblay

The set now contains the following employees:
X Bouchard
Stephane Lacroix
Joel Lamirand
Joel Tremblay
Real Tremblay
\*--------------------------------------------------------*/

