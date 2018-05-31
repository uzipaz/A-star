#ifndef STACK_CPP_INCLUDED
#define STACK_CPP_INCLUDED

#include "stack.h"

template <class T>
stack<T>::stack()
{
    CurrentSize = 0;
}

template <class T>
stack<T>::~stack()
{
    // Do nothing
}

template <class T>
void stack<T>::push(T element)
{
    data[CurrentSize++] = element;
}

template <class T>
T stack<T>::pop()
{
    return data[--CurrentSize];
}

template <class T>
T stack<T>::getTopElement()
{
    return data[CurrentSize - 1];
}

template <class T>
bool stack<T>::isEmpty()
{
    return (CurrentSize == 0);
}

template <class T>
int stack<T>::getNumOfElements()
{
    return CurrentSize;
}

#endif
