#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <iterator>
#include <numeric>
#include <functional>



using namespace std::placeholders; 

int fct_example(int arg1,int arg2,int arg3){
	arg1++;
	arg2++; 
	arg3++; 
	return(arg1+arg2+arg3);
}

int main(){
	auto bind_3args = std::bind(fct_example,_1,_2,_3); //bind will return an another function, need three agrument 
	//same as auto bind_3args = std::bind(fct_example,std::placeholders::_1,_2,_3);
	auto bind_2args = std::bind(fct_example,5,_1,_2); 
	auto bind_1args = std::bind(fct_example,10,_1,7); 
	//same as auto bind_1args = std::bind(&fct_example,10,_1,7); 

	int res1 = bind_3args(6,7,8); //return 24 6+1+7+1+8+1 = 
	int res2 = bind_2args(8,9); //return 25 5+1+8+1+9+1 = 25
	int res3 = bind_1args(97); //return 117
}