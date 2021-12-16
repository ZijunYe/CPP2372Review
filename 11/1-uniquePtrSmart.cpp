

/*																
 
In the function fct(), the pointer variable p expires but the 50 integers (dynamic array) still exists in the program!

void fct()
{
  int* p;          // p is a pointer located on stack
  
  p = new int[50]; // 50 integers are stored on heap memory

}

 p no longer exists but the 50 integers STILL EXSIST! This is a challenge!
 
 So why not make pointers responsible for cleaning up the dynamically allocated memory!
 
 
 void fct_with_smart_pinter()
{
  // define p as an smart pointer which points to a dynamic array of size 50
  
  // no delete statements but still it is correct!
 
}
 
 
 
 
 --Smart pointers are objects, implemented by template classes, which automatically delete the dynamic memory allocated by them which are not needed anymore.
 
 --Smart pointers are for dynamic memory (heap memory)


1- unique pointers:  unique_ptr
2- shared pointers:  shared_ptr
3- weak pointers:    weak_ptr
4- auto pointers: (deprecated)

We can dereference a smart pointer (* name_of_smart_pointer), access a particular member of the object they are pointing (name_of_smart_ptr ->) but they don't support pointer arithmetic (no support for ++ or --)

*/

//unique pointers: ownership is exclusive; not copyable; can not be assigned;
// we can move them by applying the move semantics 
#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

class A_Class {
	int a;
public: A_Class() {a = 99;}
	    A_Class(int i) { a = i;}
		~A_Class() { }
		int return_attribute() { return a; }
	    };



int main() {

	std::unique_ptr<A_Class> smart_uniquePtr {new A_Class()};
// std::unique_ptr<A_Class> smart_uniquePtr = new A_Class; // ERROR

	std::unique_ptr<A_Class> S_ptr = std::make_unique<A_Class>();
	std::unique_ptr<A_Class> S_ptr2 = std::make_unique<A_Class>(54);
	auto S_ptr3 = std::make_unique<A_Class[]>(3); //ptr3 points to array of size 3
	std::cout << S_ptr3.get()[2].return_attribute();

	
	std::unique_ptr<A_Class> S_ptr4;
	//ptr4 = ptr2; ERROR, NO Assign to a unique ptr
	S_ptr4 = std::move(S_ptr2);

	std::vector<std::unique_ptr<A_Class>> vector_ofsmartptr_A;
 // vector_ofsmartptr_A.push_back(S_ptr4); causes error, NO COPY in unique pointers
	vector_ofsmartptr_A.push_back(std::move(S_ptr4));


	{
		std::unique_ptr<A_Class> S_ptr5 = std::make_unique<A_Class>(111);

	} /* S_ptr5 expires here and so automatedly deletes the dynamic memory. */



}


