#ifndef ARRAYLIST_CPP_INCLUDED
#define ARRAYLIST_CPP_INCLUDED

#include "ArrayList.h"

template <class T>
ArrayList<T>::ArrayList()
{
    TotalSize = DEFAULT_SIZE;
    data = new T[TotalSize];
}

template <class T>
ArrayList<T>::ArrayList(int size)
{
    TotalSize = size;
    data = new T[TotalSize];
}

template <class T>
ArrayList<T>::ArrayList(T* arr, int size)
{
    TotalSize = size;
    data = new T[TotalSize];

    for (int i = 0; i < TotalSize; i++)
        data[i] = arr[i];
}

template <class T>
ArrayList<T>::~ArrayList()
{
    delete [] data;
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& Other)
{
    this->TotalSize = Other.TotalSize;
    this->data = new T[TotalSize];

    int i;
    for (i = 0; i < TotalSize; i++)
        data[i] = Other.data[i];
}

template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)
{
    delete [] data;

    this->TotalSize = rhs.TotalSize;
    this->data = new T[rhs.TotalSize];

    int i;
    for (i = 0; i < TotalSize; i++)
        data[i] = rhs.data[i];

    return *this;
}

template <class T>
void ArrayList<T>::expand()
{
    int NewSize = TotalSize * INCREASE_FACTOR;
    T* temp = new T[NewSize];

    for (int i = 0; i < TotalSize; i++)
        temp[i] = data[i];

    delete [] data;

    data = temp;
    TotalSize = NewSize;
}

#endif
