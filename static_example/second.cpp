#include<iostream>
#include "Add.h"

void foo(){
	i++;  // i become 6 
	e++; 
	std::cout<<"in the foo method of second.cpp"<<i; 
	std::cout<<std::endl; 
	i = 0; //i become 0 
	e = 0; //e become 0 


}