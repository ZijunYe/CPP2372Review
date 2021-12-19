
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

void fct(int tab[], int size) {
    
    for (int i=0; i<size; i++)
        std::cout<<tab[i]<<",";
    std::cout<<std::endl;
}

class MyClass{
    public:
        MyClass();
        ~MyClass(); 
        MyClass(const MyClass &rhs){}; //copy constructor 
    private:
        int a; 

}


int main()
{


    vector<MyClass> mc(3); 
    MyClass obj1,obj2,obj3; 
    mc.push_back(obj1); //calling copy constructor to the temporary obect and then deleting the temp object 
    mc.push_back(obj2);
    mc.push_back(obj3);


     // vector declaration
    vector<int> a;
    // vector<Triangle*> t;
    vector<int> b(50); // Initial to  50 items.
    
    cout <<  "vector size : " << b.size() << ", "
            << "vector capacity : " << b.capacity() << endl;
    cout <<  b[0] << " " <<  b[1] << " " <<  b[2] << " " << endl;
    
    vector<int> v(10, 2); // the 10 elements are initialized to 2

    cout <<  "vector size  : " << v.size() << ", "
            << "vector capacity : " << v.capacity() << endl;
    v.push_back(30);

    // v[100] = 10;  // undefined behavior (out of bounds)

    cout <<  "vector size  : " << v.size() << ", "
            << "vector capacity : " << v.capacity() << endl;

     // regular iterators
    vector<int> c(10, -1);
    cout << "After the iteration, c = {";
    for (vector<int>::iterator it = c.begin();
                                        it != c.end(); it++) {
        *it += 3;

        if (it == c.begin()) cout << *it;
        else cout << ", " << *it;
    }
    cout << "}" << endl;


    // reversed iterators
    cout << "After the iteration, y = {";
    vector<int> y(4, 10);
    y.push_back(8);
    y.push_back(6);
    y.push_back(4);
    vector<int>::reverse_iterator it2;
    it2 = y.rbegin();
    while (it2 != y.rend()) {
        *it2+=3;

        if (it2 == y.rbegin()) cout << *it2;
        else cout << ", " << *it2;

        it2++;
    }
    cout << "}" << endl << endl;
    
    //The conversion vector -> int* (a regular array) is possible.
    fct(&y[0], y.size());
    // fct(&*y.begin(), y.size());
    
        // multidimensional vectors
    // vector of 3 rows and 2 columns
    // elements initialized to 0
    vector< vector<int> > x(3, vector<int>(2, 0));
    vector< vector<int> >::iterator it;
     // note that spaces in vector< vector<int> >
    // are important


    //version1
    cout << "Values of the multidimensional vector  "
            << "after the iteration : " << endl;
    for (it = x.begin(); it != x.end(); it++) {
        vector<int>::iterator it2;
            cout << "{";
            for (it2 = (*it).begin(); it2 != (*it).end(); it2++) {
                *it2 += 3;

                if (it2 == (*it).begin()) cout << *it2;
                else cout << ", " << *it2;
            }
            cout << "}" << endl;
    }


    //version2
    //another way to loop through the vector
    for(int i = 0; i < x.size(); i++){
        for(int j = 0; j < x[i].size(); j++){
            cout<< x[i][j]<< " "; 
        }
    }


    //version3
    //thrid way to loop through the vector
    for(auto & i : x){
        for(auto &j: i){

        }
    }
        
     // vector<bool> are special: 
    // they use a compact representation where one bool is equivalent to one bit
}

/*--------------------- results -------------------------*\
vector size : 50, vector capacity : 50
0 0 0
vector size  : 10, vector capacity : 10
vector size  : 11, vector capacity : 20
After the iteration, c = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
After the iteration, y = {7, 9, 11, 13, 13, 13, 13}

13,13,13,13,11,9,7,
Values of the multidimensional vector  after the iteration :
{3, 3}
{3, 3}
{3, 3}

\*--------------------------------------------------------*/




