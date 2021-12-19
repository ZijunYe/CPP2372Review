# Smart Pointer
smart pointer
- pointer just for heap, cannot points to stack memory
- automatically delete the heap that they pointing to 

### type of smart pointer
1. unique-ptr ptr (ptr is the owner of A)
- ptr is the only pointer to A 
- A in the heap 
- when delete ptr, A will automatically deleted without explicit calling delete[]A
- no copyable 
- no assignable 
- movable --> ptr2 = std::move(ptr); 
	- ptr will become nullptr
```
std::unique_ptr<Type> pointername {new objectNameConstructor()}; //1
std::unique_ptr<Type> pointername = std::make_unique<ClassName>(); //2
std::vector<std::unique_ptr<Type>> vector_ofSmartPtr; 

vector_ofSmartPtr.push_back(std::move(pointername)); //add pointer to vector 
//unable to directlly push_back(pointername); Error because unique pointer are not copyable 

```



2. shared-ptr prt(shared ownership)

```
shared-ptr ptr1 = B
shared-ptr ptr2 = B
ptr2.use_count() // is 2 use for count owner of the object

ptr2.reset(); //ptr become reset 
ptr.use_count(); //is 1
```
- when use_count == 0 is true, the dynamic memory(heap) is deleted

sample code: 
```
std::shared_ptr<Type> pointername = {new objectConstructor}; 
std::shared_ptr<Type> pointername = std::make_shared<Type>(); 
//two pointer assignment are the same

std::shared_ptr<Type> ptr{pointername}; //share pointername with ptr

int count = ptr.use_count(); 
ptr.reset(); 

//add pointer to the vector 
std::vector<std::shared_ptr<Type>> vector_ofshareptr; 
vector_ofshareptr.push_back(ptr); // no error!


//customized deleter 
std::shared_ptr<Type> ptr{new ObjectConstructor, customizedDeleteFunction}; 
```

3. weak_ptr(circular dependency)
obj1 pointing to obj2 
obj2 pointing to obj1

- do not use use_count() and use_count never gets zero 
- cannot delete obj1 or obj2
- declare one of pointer as shared pointer and another as weak pointer


# raw pointer --> int *ptr = object; 
- 
- the expire of pointer doesn't mean the memory location of the object will be expire 
- it need use ```delete[] ptr; ```
