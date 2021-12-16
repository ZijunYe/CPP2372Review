
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>
#include <functional>

using namespace std;

template < class V >
std::ostream& operator<< (std::ostream &out, std::vector<V> &v) {
  copy(v.begin(), v.end(), ostream_iterator<V>(out, " ") );
  return out;
}


bool odd(int a) {
    return (a%2 == 1);
}

bool multiple3(int a) {
    return (a%3 == 0);
}

bool comp_function(int i,int j) { return (i<j); }

struct myClass {
  bool operator() (int i,int j) { return (i<j);}
} myObject;

class Smallest {
  
     int c;  
    public:
      Smallest(int c) : c(c) {}
      void setC(int c) { this->c=c;} 
      bool operator()(int i) {return i<c;} 
};

void quicksort(vector<int>::iterator it1,
                                    vector<int>::iterator it2) {
    if (it2-it1 <= 1)
        return;

    // the pivot is the first element
    vector<int>::iterator it = partition(it1+1, it2,
                                     bind(less<int>(), placeholders::_1, *it1));
   // puts the pivot back in its place
    swap(*it1,*(it-1));

    quicksort(it1, it-1);
    quicksort(it, it2);
}

int main()
{
    
   Smallest pp(7);
   
   pp.setC(22);
   if (pp(12)) std::cout<< "Yes \n"; else std::cout<< "no "; 
   
   vector<int> v;
   v.push_back(7);
   v.push_back(3);
   v.push_back(2);
   v.push_back(5);
   v.push_back(6);
   v.push_back(11);
   v.push_back(12);

   vector<int>::iterator it, it2;

   it = find_if(v.begin(), v.end(), odd);
   cout << "The first odd value is " << *it << endl;

   if (it!=v.end()) {
     it = find_if(it+1, v.end(), odd);
     cout << "The 2nd odd value is " << *it << endl;
   }

   it = min_element(v.begin(), v.end());
   cout << "The smallest value is " << *it << endl;

   it = max_element(v.begin(), v.end());
   cout << "The greatest value is " << *it << endl;

   it = partition(v.begin(), v.end(), odd);

   cout << "The following values are odd : ";
   for (it2 = v.begin(); it2 != it; ++it2)
       cout << " " << *it2;
   cout << endl;

   cout << "The following values are even : ";
   for (it2 = it; it2 != v.end(); ++it2)
       cout << " " << *it2;
   cout << endl;

   cout << "Here are the values after partition : ";
   it = partition(v.begin(), v.end(), multiple3);
   cout << v << endl;
   
  int ints[] = {32,71,12,45,26,80,53,33};
//   it = partition(ints, ints+8, multiple3);


  vector<int> myVector (ints, ints+8);
  // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
  sort (myVector.begin(), myVector.begin()+4);
  //(12 32 45 71)26 80 53 33

  // using comp_function as comp
  sort (myVector.begin()+4, myVector.end(), comp_function);
  // 12 32 45 71(26 33 53 80)

  // using object as comp
  sort (myVector.begin(), myVector.end(), myObject);
  //(12 26 32 33 45 53 71 80)

  // print out content:
  cout << "myVector contains:";
  for (it=myVector.begin(); it!=myVector.end(); ++it)
    cout << " " << *it;

  cout << endl;


    cout << v << endl;

     // accumulate (add by default) the content
    // of the vector between begin and end in the third argument
    int a = accumulate(v.begin(), v.end(), 0);
    cout << "Addition result: " << a << endl;

    // sort the first four values of the vector with the
    // the function less
    sort(v.begin(), v.begin()+4, less<int>());

    cout << "Result of the less sort (first 4 values): ";
    cout << v << endl;

    // sort the first four values of the vector with the
    // function greater
    sort(v.begin(), v.begin()+4, greater<int>());

    cout << "Result of sorting greater (first 4 values): ";
    cout << v << endl;

    auto op1 = std::bind(std::greater<int>(), placeholders::_1, 10);
    op1(5); // equivalent to std::greater<int>()(5, 10)
    
    auto op2 = std::bind(std::greater<int>(), 10, placeholders::_1);
    op2(5); // equivalent to std::greater<int>()(10, 5)    
    vector<int>::iterator itp = partition(v.begin(), v.end(),
                                          bind(less<int>(), placeholders::_1, v.back()));
    cout << "Result of the partition (bind 1):  ";
    cout << v << " : " << *itp << endl;

    itp = partition(v.begin(), v.end(), bind(less<int>(),v.back(), placeholders::_1));
    cout << "Result of the partition (bind 2): ";
    cout << v << " : " << *itp << endl;

   // sorting with quicksort
    quicksort(v.begin(), v.end());

    cout << "Result of the quick sort: ";
    cout << v << endl;

    // accumulate the values of the vector by multiplying them
    int c = accumulate(v.begin(), v.end(), 1, multiplies<int>());
    cout << "Result of the multiplication: " << c << endl;

    // Counting of elements meeting a condition
    cout << "The conditional counting is: " <<count_if(v.begin(),v.end(),bind(less<int>(), placeholders::_1,5)) << endl;

    // consider using lambda expressions instead of std::bind
}

/*--------------------- results -------------------------*\

Yes
The first odd value is 7
The 2nd odd value is 3
The smallest value is 2
The greatest value is 12
The following values are odd :  7 3 11 5
The following values are even :  6 2 12
Here are the values after partition : 12 3 6 5 11 2 7
myVector contains: 12 26 32 33 45 53 71 80
12 3 6 5 11 2 7
Addition result: 46
Result of the less sort (first 4 values): 3 5 6 12 11 2 7
Result of sorting greater (first 4 values): 12 6 5 3 11 2 7
Result of the partition (bind 1):  2 6 5 3 11 12 7  : 11
Result of the partition (bind 2): 12 11 5 3 6 2 7  : 5
Result of the quick sort: 2 3 5 6 7 11 12
Result of the multiplication: 166320
The conditional counting is: 2

\*--------------------------------------------------------*/




/* recommended definition of the std::partition function  *\

template <class BidirectionalIterator, class UnaryPredicate>
  BidirectionalIterator partition (BidirectionalIterator first,
                                   BidirectionalIterator last, 
                                   UnaryPredicate pred)
{
  while (first!=last) {
    while (pred(*first)) {
      ++first;
      if (first==last) return first;
    }
    do {
      --last;
      if (first==last) return first;
    } while (!pred(*last));
    swap (*first,*last);
    ++first;
  }
  return first;
}

\*-----------------------------------------------------*/


