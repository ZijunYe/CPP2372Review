
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    multimap<string, int> m;    
    multimap<string, int>::iterator it;

    m.insert(make_pair("pear", 22));
    m.insert(make_pair("apple", 52));
    m.insert(make_pair("grape", 45));
    m.insert(make_pair("orange", 7));


    it= m.insert(make_pair("apple", 27)); //we can have duplicate key 

     // insertion with an index for efficiency
    it= m.insert(it, make_pair("applette", 8));//it represent iterator position 

    for (auto it2= m.begin(); it2!= m.end(); it2++) {

        cout << "[" << it2->first << "," << it2->second << "] ";
    }
    cout << endl;

     // insert returns the insertion position
    cout << "[" << it->first << "," << it->second << "] " << endl;

 // the call to the find method returns
    // the first element equal to the key
    it= m.find("orange");
    if (it!=m.end())
      cout << "[" << it->first << "," << it->second << "] " << endl;

     // equal_range returns a pair of iterators
    pair<multimap<string, int>::iterator,
                            multimap<string, int>::iterator > pit;
    pit = m.equal_range("apple");

    for (it = pit.first; it != pit.second; it++) {
        cout << "[" << (*it).first << ", "
                            << (*it).second << "] ";
    }
    cout << endl;

     // erase returns the number of destroyed elements
    cout <<  m.erase("apple")<<endl;

    for (auto it2= m.begin(); it2!= m.end(); it2++) {

        cout << "[" << it2->first << "," << it2->second << "] ";
    }
    cout << endl;
}

/*--------------------- results -------------------------*\
[apple,52] [apple,27] [applette,8] [grape,45] [orange,7] [pear,22]
[applette,8]
[orange,7]
[apple, 52] [apple, 27]
2
[applette,8] [grape,45] [orange,7] [pear,22]

\*--------------------------------------------------------*/
