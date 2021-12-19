

#include <iostream>
#include <string>
#include <map>

using namespace std;



// A map associates a key with a value.
// Its elements are ordered by key.
// A map has only one value per key.
// A map uses the < to compare / sort elements.
// Iterators are never invalidated by insertions or deletions.
// Be careful, the find uses the < to find an element
// Equivalence: !(a < b) && !(b < a);
// Insert : insert is more efficient
// update : [] is more efficient
// Beware of tests with [] for keys that do not exist: if (m["apple"] > 10)
// If the key does not exist, an int is created by default and the key apple is inserted. 
// This int contains anything.





int main()
{
    map<string, int> m;
    m["apple"] = 2;
    m["pear"] = 5;
    m["orange"] = 4;
    m["melon"] = 7;

    map<string, int>::iterator it;
    int total = 0;

    for (it = m.begin(); it != m.end(); it++) {
         // each element of the iterator is a pair
        // with a "first"(key) and a "second"(value)
        total += it->second;
    }
    
    cout << total << endl;

    it = m.find("apple");
    // returns the iterator to the element with
    // key "apple

    if (it != m.end())  { // I found it!
        m.erase(it);   // m.erase(m.find("apple")
        cout << "apple has been erased." << endl;
    }
    else
        cout << "There is no apple in the map." << endl;

}
/*--------------------- results ---------------------*\
    18
    apple has been erased.
\*----------------------------------------------------*/








