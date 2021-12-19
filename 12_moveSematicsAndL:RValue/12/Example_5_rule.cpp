#include <iostream>
#include <vector>


class SimpleClass // with Rule of 5 enabled!
{
private:
	int *ptr;

public:
	// default constructor(no-arguments constructor)            (DC)
	SimpleClass() { ptr = new int[2]; ptr[0] = 0; ptr[1] = 0;
	}


	// overloaded constructor (constructor with one argument)   (OVL_C)
	SimpleClass(int i) { ptr = new int[2]; ptr[0] = i; ptr[1] = i; }


	// copy constructor                 (CC)
	SimpleClass(const SimpleClass& rhs_for_init)
	{ int i = *(rhs_for_init.ptr);
	  ptr = new int[2];
	  ptr[0] = i; ptr[1] = i;
	}


	// copy assignment operator                    (CAO)
	SimpleClass& operator= (const SimpleClass& rhs_of_assignment) {
		if (this != &rhs_of_assignment) // rhs and lhs are not the same object
		{
			delete[] ptr;
			int i = *(rhs_of_assignment.ptr);
			ptr = new int[2];
			ptr[0] = i; ptr[1] = i;
		}

		return *this;
	}


	// move constructor                        (MC)
	SimpleClass(SimpleClass&& rhs_for_init_is_Rvalue) noexcept {
		ptr = rhs_for_init_is_Rvalue.ptr;
		rhs_for_init_is_Rvalue.ptr = nullptr;
	}

	// move assignment operator               (MAO)
	SimpleClass& operator= (SimpleClass&& rhs_of_assignment_is_Rvalue) noexcept {
		if (this != &rhs_of_assignment_is_Rvalue) // rhs and lhs are not the same object
	    //If we aren't attempting to move the object inside itself, then...
		{
			delete[] ptr;
			ptr = rhs_of_assignment_is_Rvalue.ptr;
			rhs_of_assignment_is_Rvalue.ptr = nullptr;
		}

		return *this;
	}


	//destructor                      (D)
	~SimpleClass() { 
		delete[] ptr;   }

};


int main() {

	SimpleClass sc; //calls (DC) 
	SimpleClass sd; //calls (DC) 
	SimpleClass se = sd; //calls (CC) 
	sc = sd; //calls (CAO) 
	SimpleClass sf{ 7 }; //calls (OVL_C) 


	std::vector<SimpleClass>vec;
	vec.push_back(7); //calls MC
	
	sd = SimpleClass(); //calls   (MAO)

}