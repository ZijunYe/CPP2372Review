#include <iostream>
#include <algorithm>
#include <vector>

int main(){
	int j(5); 
	int i(4); 

	//no name 
	//automatic inline 

	auto lambda_fct = [](int arg1,int &arg2){arg2 = arg1 + 11; arg1 = 83;}; 
	//[](int arg1,int &arg2)->int {arg2 = arg1 + 11; arg1 = 83; return arg1}; 
		//will return a int 

	//[] --> sign of is lambda function 
	//list of arguments 
	//body of function 
	//arg1 call by value 
	//arg2 call by reference (arg2 will change consistantly)

	lambda_fct(i,j); 


	[](int a){return a < 5;}; 
	std::sort(v.begin(),v.end(), [](int a){return a < 5;} ); 


	[](int &a){ a = a+10;}; 
	std::for_each(v.begin(),v.end(),[](int &a){ a = a+10;} ); 
	//every method in v will be add 10 value 


}