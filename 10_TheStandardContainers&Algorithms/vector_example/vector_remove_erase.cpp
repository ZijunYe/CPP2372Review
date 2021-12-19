
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template <typename T>
void display(std::string name, const T &v) {

    auto it= v.begin(); 

    cout << name << " [" << v.size() << "]:";

    while (it!=v.end()) {

        cout << *it;
        ++it;

        if (it!=v.end())
            cout << ", ";
    }

    cout << " | {" << v.capacity() << "}";

    cout << endl;
}

int main()
{
    // iterators allow to define intervals
    // to the construction for the initialization of another vector


    vector<int> v1(5, 3), v(v1.begin(), v1.end());// v is copy of v1
    vector<int>::iterator it = v.begin();

    display("v1", v1);
    display("v", v);

    it++; it++; //it now is points to the 3th element in vector 

   // Warning: Iterators can be invalidated 
    // during an insertion or removal.
    
    // inserts an element before the current position
    it= v.insert(it, 99);
   // the iterator is now at the position
    // of the new element.
    display("after insert", v);

    // delete
    it++; //it now is points to the 4th element in vector 
    it = v.erase(it);
    display("after erase 1", v);
    
    it= v.erase(v.begin()+2, v.end());
    display("after erase 2", v);
    
     // we can increase the capacity of a vector
    display("v1 (before reserve)", v1);
    v1.reserve(80); // if this number is smaller than the capacity:
                    // no effect
    display("v1 (after)", v1);

   // no method to reduce the capacity of a vector
    display("before reduction", v);
    vector<int>(v.begin(), v.end()).swap(v);
    display("after reduction", v);

    // assignation
    v.assign(v1.begin() + v1.size()/2, v1.end());
    display("after assign", v);
    v.clear();
    display("after clear", v);

    for (vector<int>::iterator it = v1.begin() + v1.size()/2;
                                            it != v1.end(); it++)
        v.push_back(*it);

    display("after loop", v);

     // Where iterators are required, pointers can always be used   
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    v.assign(a+3, a+8);
    
    display("after assign", v);
    
    v.push_back(10);
    v.insert(++v.begin(),10);
    v[4]=10;
    display("before", v);
    
    // v1.assign(v.begin(),v.end());
    v1= v;
    
    std::list<int> liste(v.begin(),v.end());

    vector<int>::iterator p;
    // remove is an algorithm


    p = std::remove(v1.begin(), v1.end(), 10);
        // move the *q elements of the container so that
    // so that [v.begin(), p[, we find only elements
    // elements such that !(*q == value)

    
    display("after remove", v1);
    std::cout << "*p=" << *p << std::endl;
    
    // the erase-remove idiom
    v.erase(remove(v.begin(), v.end(), 10), v.end());
    display("after erase-remove", v);

    // list has its own remove
    liste.remove(10);
    std::cout << "list after remove:";
    for(auto i=liste.begin(); i != liste.end(); ++i) std::cout << *i << " ";
    std::cout << std::endl;
}

/*******************************************\
v1 [5]:3, 3, 3, 3, 3 | {5}
v [5]:3, 3, 3, 3, 3 | {5}
after insert [6]:3, 3, 99, 3, 3, 3 | {10}
after erase 1 [5]:3, 3, 99, 3, 3 | {10}
after erase 2 [2]:3, 3 | {10}
v1 (before reserve) [5]:3, 3, 3, 3, 3 | {5}
v1 (after) [5]:3, 3, 3, 3, 3 | {80}
before reduction [2]:3, 3 | {10}
after reduction [2]:3, 3 | {2}
after assign [3]:3, 3, 3 | {3}
after clear [0]: | {3}
after loop [3]:3, 3, 3 | {3}
after assign [5]:4, 5, 6, 7, 8 | {5}
before [7]:4, 10, 5, 6, 10, 8, 10 | {10}
after remove [7]:4, 5, 6, 8, 10, 8, 10 | {80}
*p=10
after erase-remove [4]:4, 5, 6, 8 | {10}
list after remove:4 5 6 8

\*******************************************/



