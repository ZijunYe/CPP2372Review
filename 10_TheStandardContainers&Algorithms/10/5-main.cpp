

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Employe {

    string name;
    int no;

   public:
    Employe(string n, int num) : name(n),no(num) {}
    bool operator<(const Employe& e) const {return no < e.no; }
};

int main()
{
    map<string, int> m;
    m["orange"] = 3; // insertion
   
 /*
Beware of tests with [] for keys that do not exist.
if (m["banana"] > 10)
If the key does not exist, an int is created by default and the banana key is inserted. This int contains anything.

It is better to use
if (m.find("banana") != m.end() && m["banana"] > 10)
*/   

    // If the object exists, returns a reference to the object
    // whose key corresponds to this request.
    // If there is no object associated to this key (the key
    // does not exist), then the default constructor is used
    // to create a reference to an object.
	
    if (m["orange"] == 3)
        m["orange"] = 7; // update

    // for more efficiency, use the insert operator
    m.insert(pair<string, int>("apple", 221));
    // fct template to create a pair;
    m.insert(make_pair("pear", 12));
    m.insert(make_pair("orange", 7));
    m.insert(make_pair("pineapple", 7));

    for (map<string, int>::iterator it= m.begin(); it!=m.end(); ++it)
        cout << "[" << (*it).first << "," << (*it).second << "] ";
    cout << endl;

    // returns a pair<iterator, bool>
    pair<map<string, int>::iterator, bool> ret; //the pair key is the iterator and value is boolean 
    ret = m.insert(make_pair("pear", 13)); //insert will return me a pair 

    if (ret.second)
        cout << "A new element has been inserted." << endl;
    else
        cout << "The element already existed. "
                << "There was no insertion." << endl;

    m.insert(make_pair("pear", 22)).first->second = 22;
   // first is the iterator pointing to the inserted/existing element.
    // second is the value in the map.
    // For an update, make_pair is not used,
    // therefore created for nothing.

    // delete an element from an iterator
    m.erase(m.find("pineapple"));

    for (map<string, int>::iterator it= m.begin(); it!=m.end(); ++it)
        cout << "[" << (*it).first << "," << (*it).second << "] ";
    cout << endl;

    // find the first element not <
    map<string, int>::iterator it= m.lower_bound("apple");
    cout << "[" << (*it).first << "," << (*it).second << "] " << endl;

    // find the first non-equivalent element
  //  it= m.upper_bound("pear");
  //s  cout << "[" << (*it).first << "," << (*it).second << "] " << endl;

    map<Employe, float> folders;
    folders.insert(make_pair(Employe("Robert",123), 15.25));
    folders.insert(make_pair(Employe("Jean",453), 14.15));
    folders.insert(make_pair(Employe("Paul",323), 25.35));
    folders.insert(make_pair(Employe("Simon",663), 20.25));

    for (auto it= folders.begin(); it!=folders.end(); ++it)
        cout << (*it).second << ", ";
    cout << endl;

}

/*------------------ results ------------------------*\
[apple,221] [orange,7] [pear,12] [pineapple,7]
The element already existed. There was no insertion.
[apple,221] [orange,7] [pear,22]
[apple,221]
15.25, 25.35, 14.15, 20.25,

\*----------------------------------------------------*/


