# vector

## Attributes
1. objects or whatever data type add to the collection, the container takes their copies and inserts to the container(lecture 11/24 00:27::22)

## How to initialize 

```
 //vector declaration 
 vector<int> a; 

 //vector initial with size 
 vector<int> a(50); 

 //vector initial with size and element set value with 2
 vector<int> a(10,2); 


 //copy another vector into this vector 
 vector v(v1.begin(),v1.end()); 
 ```


## method 

```
a.size(); 
a.capacity(); //compilier used itself to allocating and deallocating memory
a[0]; a[1]; //can access elements by index
a.push_back(30); //adding element to the vector 
a.begin(); //return the first element in the vector 
a.end(); //points to the next of end elements 
a.rbegin();//reverse begin of vector 
a.rend(); //reverse end of vector

a.insert(elemPointer,value); //insert before the elem

a.erase(iterator position); //delete the elem; 
a.erase(elemPointer, endElemPointer); //delete the elem from elemPointer to the endElemPointer

a.erase(remove(v.begin(),v.end(),numberValue),a.end()); 

a.reserve(value); //increase capacity of a vector, change the capacity to that value

```


- p = std::remove(v.begin(),v.end(),10); //*p will contain the removed element's value 
- remove doesn't not change size of the vector 
- erase-remove, first the remove function will put unwanted elememt to the end, and use erase to delete elements from new end to the old end 



## iterator to loop through each element in vector 

foward iterator 
```
for(vector<int>::iterator it = v.begin(); it != v.end(); it++){}
```

backword iterator 
```
for(vector<int>::iterator reverse_iterator it2 = v.rbegin(); it2!= v.rend(); it2++){}
```

## vector of vector 

```
vector< vector<int> > x (3, vector<int>(2,0));
```

(row, column)
















