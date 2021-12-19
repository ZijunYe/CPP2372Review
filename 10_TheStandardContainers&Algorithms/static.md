# static 

## 1. static variable (inside function)
1. intialize just once 
2. global lifetime(do not expire, until program ends)

### example 
```
int fnct(float c){
	static int x = 5; 
	x +=5; 
	cout<<x+c; 
}

int main(){
	fnct(9); 
}
```
| first Time     | second Time        |
| -------------- | ------------------ |
| x =5           | no need intialize  |
| x = 10         | x = 15             |
| cout<<14       | cout<<24           |


## 2. static class members
1. How to access static class members ClassName::staticMemberName
2. share between all object 


### example
```
class Simple{
	public:
		static int st; // binds to the class simple, all objects share st
		int a; 
		static int fntc(int i); 
}

int main(){
	//declaration of object Simple
	Simple obj1, obj2, obj3; 
	//each one of object will have their own "a" non-static members
	//but "st" is same to obj1, obj2,obj3

	obj1.st; //ERROR(incorrect)
	Simple:: st; //CORRECT access static member of object
	Simple::fnct(9); //same as to access static function of object

}
```


## 3. namespace static 
1. opposite to extern 
2. every source file which includes the header will get their own version
	it is copy of that statuc variable 

### example
see the fold (static_example)

