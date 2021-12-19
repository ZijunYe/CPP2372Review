# Standard Algorithms (predicate)

## method1 find 
```
iterator = find(a1.begin(),a1.end(),a); 
iterator = find_if(a1.begin(),a1.end(),functionName); 
```
-the third argument can be particular number
-also the third argument can be function 


## method2 max/min element in vector 
```
iterator = min_element(vector.begin(),vector.end()); 
iterator = max_element(vector.begin(),vector.end()); 
```

## method3 partition 
```
std::partition 
iterator = partition(vector.begin(),vector.end(),functionName); 
```
- the  partition split the vector into two part, first part is true that satiffy the condition, another part is false which do not satisfy the condition 
- the partition will return the first unsatisfied element to the iterator 
- if two begin, end pointer one of them satisfy the condition and position is incorrect, they need to do swap 


## method4 accumulate 
```
line(138)int number1 = accumulate(v.begin(),v.end(),1,multiplies<int>()); 
```
	- do multiplication 
	- if the number(third argument)change, then the final number will change by overall product * third argument 
```
line(176) number2 = accumulate(v.begin(),v.end(),0); 
```
- do addition
- if the last number change, the final value will do addition overall then add to the number


## method5 sort 
```
sort(v.begin(),v.end(),less<int>()); 
sort(v.begin(),v.end(),greater<int>()); 
sort(v.begin(),v.end(),functionOverload);
```

## method6 counting 
```
count(v.begin(),v.end(),5); 
//count number that equal 5 

count_if(v.begin(),v.end(),bind(less<int>(),placeholders::_1,5)); 

//count number that satisfy that bind condition 
//bind function meaning: the less method, take each vector element compare with value 5, if less than 5 then it is satified; function will return boolean 
```
- counting number of vector element 

## method7 bind 
```
std::bind
auto function = std::bind(function, argument1,argument2,argument3); 
```
- return an another function 

## method8 lambda expression 
```
[](arg1,arg2){//body of function }
```
- no name 
- automatically inline; 
- 3 parts 
- can be directly add predicate 

what is lambda? 
- fundamental for CS - programming language 
- we can write anything through functions(lambda expression)
- we can express them in math 
- introduced math in programming 
- proof theorem formular now avaliable for programming language 


