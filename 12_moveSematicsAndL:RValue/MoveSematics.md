# Move Sematics

(shallow copy,deep copy, move)
- when two pointer points to the same location 
- one of pointer will become null pointer 
- **R-value** are great for moving, instead of copying, because they are usually temporary and they can lose their state
- all temporary objects and the objects which it is not important if they lose their states, we can apply move strategy instead of copy 

obj2 = move(obj1); 
//obj1 will loses its state (values,ownerships..)

- move constructor 
- move assignment operator 

```
std::move(ptr); //generates an R-value of an L-value
```

- it returns an R-value reference to argument 

## an expression 
L-value: can be use in both lsh and rsh 
R-value: can only be used in rhs
Rvalue-> no name, no address 


### example

1. (i+5) --> R-value 
	- can only be on the rhs (int j = i+5 )
	- it cannot be on the lhs (i+5 = 10)X

2. j --> L-value
	- can use in rhs(int k = j)
	- also can use in lhs(j = 11)

3. 256 --> R-value
	- can only use in rhs (int j = 256)
	- it cannot be on the lhs (256 = i)X