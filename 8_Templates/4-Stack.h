
#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack
{
public:
   Stack(int s): size(s),current(-1),stackPointer(new T[size]){}

   ~Stack()
   {
      delete [] stackPointer;
   }

    bool push(const T &valueToPush)
    {
       if (!isFull())
       {
          stackPointer[++current] = valueToPush;
          return true;
       }

       return false;
    }

    T pull()
    {
       return stackPointer[current--];
    }

    T top(){
        if (isEmpty()) return T(); // stack is empty!
        return stackPointer[current];
    }

    bool isEmpty() const
    {
       return current == -1;
    }

    bool isFull() const
    {
       return current == size - 1;
    }

    private:
       int size;
       int current;
       T *stackPointer;
};

#endif // STACK_H