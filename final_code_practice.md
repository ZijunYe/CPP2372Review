How to use **std::copy** method to copy all the element in array? 
syntax of copy ```std::copy(input first, input last, output firstiterm); ```
```
int tab[5] ={1,4,2,7,8}
std::vector<int> v(5); 
std::copy(tab,tab+5,v.begin()); 
```

example2 
```
auto r1 = std::partition(v1.begin(),v1.end(),[] (int x){return x<10}); 
auto r2 = std::partition(r1,v1.end(),[](int x){return x>100}); 
std::vector<int> v2; 
std::copy(r2,v1.end(),std::back_inserter(v2)); 
```

How to write conversion operator& conversion constructor? 
conversion operator --> chapter9
```operator type() const{}``` 

conversion constructor --> chapter8

How to make the deep copy by using copy assignment operator? 
```
ClassName& operator =(const ClassName& rhs){
	if(this == &rhs){return *this;}
	delete ptr_to_class; 
	int num = *(rhs.ptr_to_class); 
	ptr_to_class  = new int(num); 
	return *this; 
}
```

what the abstract class has: one or more pure virtual functions. 

How to print all element in vector? 
check vector example code line 102 - 118 
``` 
vector< vector<int> > x(3, vector<int>(2, 0));
    vector< vector<int> >::iterator it;
     // note that spaces in vector< vector<int> >
    // are important


    //version1
    cout << "Values of the multidimensional vector  "
            << "after the iteration : " << endl;
    for (it = x.begin(); it != x.end(); it++) {
        vector<int>::iterator it2;
            cout << "{";
            for (it2 = (*it).begin(); it2 != (*it).end(); it2++) {
                *it2 += 3;

                if (it2 == (*it).begin()) cout << *it2;
                else cout << ", " << *it2;
            }
            cout << "}" << endl;
    }


    //version2
    //another way to loop through the vector
    for(int i = 0; i < x.size(); i++){
        for(int j = 0; j < x[i].size(); j++){
            cout<< x[i][j]<< " "; 
        }
    }


    //version3
    //thrid way to loop through the vector
    for(auto & i : x){
        for(auto &j: i){

        }
    }
        
     // vector<bool> are special: 
    // they use a compact representation where one bool is equivalent to one bit
}
```


How to write customlized compare function 
```
bool comapre(const Class&p1, const Class&p2){
	if(p1.x == p2.x){
		return p1.y < p2.y; 
	}else{
		return p1.x < p2.x; 
	}
}
```

How to manipulate lambda function?
- if the passing value need change, then it need passing by reference 
```[](int &x){}```


Avoiding memory leak --> delete ptr; ptr = nullptr; 

Move constructor &  move assignment operator 
```
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
    ```









