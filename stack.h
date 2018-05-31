#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "ArrayList.h"

template <class T>
class stack
{
public:
    stack();
    ~stack();

    void push(T element);
    T pop();

    T getTopElement();

    bool isEmpty();
    int getNumOfElements();

private:
    ArrayList<T> data;
    int CurrentSize;
};

#include "stack.cpp" // Including to avoid template classes linking errors

#endif // STACK_H_INCLUDED
