# Operator overloading

1. What’s the difference between function overloading/ function overriding / function redefining? 
- override: exactly same function name,return type, input parameter types and number of input parameters as virtual function 
- redefining: if the derived class has same function as override, but is non virtual method
- overload: same function name either have different parameters types or different number of parameters 

2. What is the function signature ? 
- name of the function 
- type input 
- number of parameters 
- return type is not include of function's signature 

3. What’s the difference between non-member function and member function? 
- member function can access left hand operand by this
- member functon(1 argument is binary, non argument is unary)
- non-member function(1 argument is unary, 2 argument is binary)


4. How does the compiler define the function as prefix or postfix? 
- by written int in argument 
- ++num; // i.operator++()
- num++; // i.operator++(int)


5. What is a friend method? Where does it define? Is it always needed for non-member functions? 
- friend method can use for non-member overloading method
- friend method can access all private attribute in the class
- if the class have getter and setter, then it is not neccessary to declare friend 

6. What is unary operator and binary operator? 
- unary and binary depends on how many argument they need in operator method 

7. What is the syntax of the conversion operator? 
- conversion operator is a member function
- it ***implicit*** converts a value of class type to the primitive type 
```
operator destination-type()const;
 ```

8. What is the difference between explicit type conversion and implicit type conversion? 

- explicit it need to do write code to explicit convert type
- implicit it do automatically 


9. What is the difference between conversion operator and conversion constructor? 
- conversion operator: class type --> primitive type 
- conversion constructor: primitive type --> class type 

10. How to change the line of code when the conversion operator or conversion constructor has “explicit” in front 
- need change static_cast<type>variableName; 
	- then it will automatically jump to casting 

For the member function, the lhs argument always needs to be the class object itself! 
IO operations must be nonmember functions 

