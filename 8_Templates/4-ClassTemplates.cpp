
#include "4-stack.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {

    Stack<int> stack(5);

    cout << "The stack is empty: " << stack.isEmpty() << endl;

    stack.push(1);
    cout << "Push: 1" << endl;

    stack.push(2);
    cout << "Push: 2" << endl;

    stack.push(3);
    cout << "Push: 3" << endl;

    stack.push(4);
    cout << "Push: 4" << endl;

    stack.push(5);
    cout << "Push: 5" << endl;

    cout << "The stack is empty: " << stack.isEmpty() << endl;
    cout << "The stack is full: " << stack.isFull() << endl;

    cout << "Pull: " << stack.pull() << endl;
    cout << "Pull: " << stack.pull() << endl;
    cout << "Pull: " << stack.pull() << endl;

    cout << "The stack is empty: " << stack.isEmpty() << endl;
    cout << "The stack is full: " << stack.isFull() << endl;
    cout << "The top object in the stack is: " << stack.top()
            << endl;

    cout << "Pull: " << stack.pull() << endl;
    cout << "Pull: " << stack.pull() << endl;

    cout << "The stack is empty: " << stack.isEmpty() << endl;
    cout << "The stack is full: " << stack.isFull() << endl;
    
    Stack<float> p2(9);

    return 0;
}

/*
The stack is empty: 1
Push: 1
Push: 2
Push: 3
Push: 4
Push: 5
The stack is empty: 0
The stack is full: 1
Pull: 5
Pull: 4
Pull: 3
The stack is empty: 0
The stack is full: 0
The top object in the stack is: 2
Pull: 2
Pull: 1
The stack is empty: 1
The stack is full: 0

*/