
// weak pointers
/*
- they are not owning relationships on dynamics memories
- they are created from shared pointers
- do not increment or decrement reference counter to a dynamic memory



The problem with shared pointers is: When there is a cyclic dependency in the application architecture, shared ptr fails to clear up the memory.
 */

#include <iostream>
#include <string>
#include <memory>
#include <sstream>
using namespace std;

class B; //forward declaration

class A {
private:
		shared_ptr<B> ptr;
public:
	A() {std::cout << "A constructor" << std::endl; }
	~A() {std::cout << "\nA destructor" << std::endl; }
	void setPtr ( shared_ptr<B> ptr_arg ) {this->ptr = ptr_arg;}
    };

class B {
private:
		shared_ptr<A> ptr1;

public:
		B(shared_ptr<A> ptr1_arg) {
							std::cout << "B constructor" << std::endl;
							this->ptr1 = ptr1_arg; }
		
		~B() { std::cout << "B destructor" << std::endl; }
};
int main ( ) {
	
shared_ptr<A> a = make_shared<A>() ;
shared_ptr<B> b =  make_shared<B>(a) ;

a->setPtr ( b );

// the destructors are not called.
} 







/* The solution: Either the application architecture has to be refactored to eliminate circular dependencies, or we can utilise weak ptr to fix the problem. */


    //      THE SOLUTION
/*
#include <iostream>
#include <string>
#include <memory>
#include <sstream>
using namespace std;
class B; // forward declaration
class A {
private:
		shared_ptr<B> ptr;
public:
	A() {std::cout << "A constructor" << std::endl; }
	~A() {std::cout << "\nA destructor" << std::endl; }
	void setPtr ( shared_ptr<B> ptr_arg ) {this->ptr = ptr_arg;}
    };

class B {
private:
		weak_ptr<A> ptr1;

public:
		B(shared_ptr<A> ptr1_arg) {
							std::cout << "B constructor" << std::endl;
							this->ptr1 = ptr1_arg; }
		
		~B() { std::cout << "B destructor" << std::endl; }
};
int main ( ) {
	
shared_ptr<A> a = make_shared<A>() ;
shared_ptr<B> b =  make_shared<B>(a) ;

a->setPtr ( b );


}    */
// output:
//A constructor
//B constructor

//A destructor
//B destructor


