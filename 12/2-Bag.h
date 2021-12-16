
#ifndef BAG_H
#define BAG_H

#include <iostream>
#include <stdexcept>
#include <random>
using namespace std;

// Any class with dynamic allocation should have:
// a copy constructor
// a move constructor
// a copy operator =
// a move operator = 
// a destructor

template <class T, int capInitial=64>
class Bag {

private:

    T* bag;
    int size;
    int capacity;

        // to generate a pseudo-random sequence
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;

    void increaseCapacity(int cap);
    void copy(const Bag &b);

public:

    Bag() : size(0), capacity(capInitial), generator(7437843) {
        bag= new T[capacity];
    }
    explicit Bag(int cap) : size(0), capacity(cap), generator(7413879) {
        if (capacity<=0) capacity=capInitial;
        bag= new T[capacity];        
    }
    Bag(const Bag& b) : bag(nullptr) { 
        std::cout << "copy constructor\n";
        copy(b); }
    
    // move constructor
    Bag(Bag&& b) { 
        std::cout << "move assignment\n";
        
        this->bag= b.bag;  
        capacity= b.capacity;
        size= b.size;
        b.bag= nullptr;
        b.capacity= b.size=0;
    }
    
    ~Bag() { 
        std::cout << "Destructor of the bag with capacity " << capacity << std::endl;
        delete[] bag; 
    }

    Bag& operator=(const Bag &b); // L-value
    
    // move assignment
    Bag& operator=(Bag &&b) { // R-value
        
        std::cout << "move assignment\n";
        if (this != &b) {

            std::swap(this->bag,b.bag);  
            std::swap(capacity,b.capacity);
            std::swap(size,b.size);
        }

        return *this;
    }
    
    Bag& operator+=(const T &element);
    Bag& operator+=(Bag &b);
    T operator*();

    int getTaille() const { return size; }
    int getCapacity() const { return capacity; }
};


template <class T, int capInitial>
Bag<T,capInitial>& Bag<T,capInitial>::
        operator=(const Bag<T,capInitial> &b) {

    std::cout << "assignment\n";
    if (this != &b) {

        copy(b);
    }

    return *this;
}

template <class T, int capInitial>
Bag<T,capInitial>& Bag<T,capInitial>::
        operator+=(const T &element) {

    if (size==capacity)
        increaseCapacity(2*capacity);

    bag[size++]= element;

    return *this;
}


template <class T, int capInitial>
Bag<T,capInitial>& Bag<T,capInitial>::
        operator+=(Bag &b) {

    for(int i=0; i<b.getTaille(); i++) {
        *this += b.bag[i];
    }

    return *this;
}

template <class T, int capInitial>
T Bag<T,capInitial>::
        operator*() {

    if (size==0){
        throw invalid_argument("The bag is empty");
        // return T();
    }

    int index= distribution(generator) %size;
    T tmp(bag[index]);

    bag[index]= bag[--size];

    return tmp;
}


template <class T, int capInitial>
void Bag<T,capInitial>::
        copy(const Bag &b) {

    delete[] bag;

    capacity= b.capacity;
    size= b.size;

    bag= new T[capacity];

    for (int i=0; i<size; i++)
        bag[i]= b.bag[i];

}


template <class T, int capInitial>
void Bag<T,capInitial>::
        increaseCapacity(int cap) {

    capacity= cap;
    T *tmp= new T[capacity];

    for (int i=0; i<size; i++)
        tmp[i]= bag[i];

    delete[] bag;

    bag= tmp;
}


#endif // BAG_H