#include "Add.h"
using namespace std; 
 

int e = 2; 

int main(){
	foo(); // the final result will not effect to the variable i 
	i++; // i = 6 
	i++; // i = 7
	i++; // i = 8
	cout<<"in the main() method: " << i; 
	std::cout<<std::endl; 
	return 0 ; 
}