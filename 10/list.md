# List 
- list is great for adding and remove pointers
- travering the list need to keep track all the elements and unable to access by index
- vector can direct access to the element, but list can not direct access


## method of list 
``` 
list.push_back(a); //add element at back 
list.push_front(a); //add element at beginning 
list.begin()
list.end()
list.insert(element,value); //add element value before the element 
list.sort(); 

list.sort(compare); //list.sort(provided function); 

list.remove(value); //remove all the elements has "value"


list.erase(iterator); // iterator will become invalid 
```


