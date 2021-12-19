
#include <iostream>

int value;

int &fct1() {//return the variable name 
    
    return value;
}

/*
function return type is reference
fct1 is the variable 

fct1() = 98; //correct 
int j = fact1();//correct 
fct1 --> Lvalue
*/

int *fct(){ //return an address 
    return value; 
}

/*
fct() = 98;//not correct,because function will return a reference
int *j = fct1(); //correct
fct() --> R value
*/ 

int fct2() { //return the value such as 12
    
    return value;
}

/*
fct2() = 98;  // 12 = 98 not correct
int j = fct2(); 
R-value
*/

// L-value versus R-value
// left value versus right value
// a left value is an expression that can be found on the left of an =
// a left value refers to a memory space which we can have the address of &

// parameter: reference to a left value
void fct(int &v) {
    
    std::cout << "inside fct(&)\n";
}

// parameter: reference to a constant left value
void fct(const int &v) {
    
    std::cout << "inside fct(const &)\n";
}
//fct(90)will give error 
// int j = 90; fct(j)--> is ok

// parameter: reference to a right value
void fct(int &&v) {
    
    std::cout << "Inside fct(&&)\n";
}
//fct(90) is ok, because 90 is R-value

// parameter: reference to a right value
void mystere(int &&v) {
    
    std::cout << "inside mystere\n";
    fct(v); // when a right value has a name, it becomes a left value! 
}

int main()
{
    int x,y;
    x= 5; 
    y= x; // x and y are left values
    
    x= y+5; // y+5 is a right value
    x= fct2(); // fct2() is a right value
    
    const int c{9};
    const int *pc{&c}; // c and pc are left values
    
    fct1()=8; // fct1() is a left value here
    
    int &ref{x}; // a reference can only be initialized with a left value
    
    const int &a=10; // yes because the right value 10 is transformed into an anonymous constant variable by conversion
    // int anon=10;
    // const int &a=anon;

    
    std::cout << "fct(x) => ";
    fct(x); //calls line 22
    std::cout << "fct(c) => ";
    fct(c); //calls line 28
    
    std::cout << "fct(fct2()) => ";
    fct(fct2()); //calls line 11 then 34
    std::cout << "fct(x+5) => ";
    fct(x+5);//calls line  34
    std::cout << "fct(std::move(x)) => ";
    fct(std::move(x)); //calls line 34
    //x is an L-value 



    //std::move() --> generates an R-value of an L-value 
    
    mystere(fct2()); //calls line  11 then 40 then 22
    
    return 0;
}


/* output
fct(x) => inside fct(&)
fct(c) => inside fct(const &)
fct(fct2()) => Inside fct(&&)
fct(x+5) => Inside fct(&&)
fct(std::move(x)) => Inside fct(&&)
inside mystere
inside fct(&)

*/

