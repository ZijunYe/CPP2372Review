#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

/*
// shared pointers:

- one object on the heap memory is manages by several shared_ptrs (not exclusive)
- they have shared ownership relationship
- can be assigned and copied (which are not supported in unique pointers)
- can be moved
- when the number of shared-pointer to the same heap-allocated memory get zero, the dynamic memory is destroyed.

*/
class A_Class {
	int a;
public: A_Class() {a = 99;}
	    A_Class(int i) { a = i;}
		~A_Class() { }
		int return_attribute() { return a; }
	    };

void customDeleter(A_Class* rawPointer)
{
	cout << "customized deleteII " << std::endl;
	delete rawPointer;
}



int main() {

	std::shared_ptr<A_Class> s_pt1 { new A_Class {100} };
	std::shared_ptr<A_Class> s_pt2 = std::make_shared<A_Class>(7);

	std::shared_ptr<A_Class> s_pt3 { s_pt1 }; 

	std::cout << s_pt3.use_count(); // 2

	std::shared_ptr<A_Class> s_pt4 { s_pt1 };

	std::cout << s_pt3.use_count(); // 3

    std::cout << std::endl;
	
	s_pt1.reset();// elimanating one of the owners, still the dynamic memory exists 
	// the above statement: s_pt1= nullptr; use_cout --;

	std::cout << s_pt3.use_count(); // 2

	   std::cout << "\n---------" << std::endl;

	{
		std::shared_ptr<A_Class> s_pt4 { new A_Class {100}, 
		               	[] (A_Class* ptr) { cout << "customized deleterI";  delete ptr; } };
		std::shared_ptr<A_Class> s_pt5 { s_pt4 };
			std::cout << s_pt4.use_count(); // 2

	} // line 46 and 11 are called
	
   std::cout << "\n---------" << std::endl;
		
	{
		std::shared_ptr<A_Class> s_pt6 { new A_Class {33}, customDeleter };
		std::shared_ptr<A_Class> s_pt7 { s_pt6 };
		std::cout << s_pt7.use_count(); //2

	}// line 15 and 11 are called


	std::shared_ptr<A_Class> a1 = std::make_shared<A_Class>(7);
	std::shared_ptr<A_Class> a2 = std::make_shared<A_Class>(8);
	std::shared_ptr<A_Class> a3 = std::make_shared<A_Class>(9);

	std::vector<std::shared_ptr<A_Class>> vector_of_Aclassptrs;
	vector_of_Aclassptrs.push_back(a1);//no error! because a1 is a shared pointer, not an unique pointer
	vector_of_Aclassptrs.push_back(a2);
	vector_of_Aclassptrs.push_back(a3);

	for (const auto& v : vector_of_Aclassptrs) {
		std::cout << (*v).return_attribute() << std::endl; // 7 8 9
	}






}


