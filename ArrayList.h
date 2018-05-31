#ifndef ARRAYLIST_H_INCLUDED
#define ARRAYLIST_H_INCLUDED

const int DEFAULT_SIZE = 30;
const int INCREASE_FACTOR = 3;

template <class T>
class ArrayList
{
public:
    ArrayList();
    ArrayList(int size);
    ArrayList(T* arr, int size);
    ArrayList(const ArrayList<T>& Other); // Copy Constructor

    ~ArrayList();

    ArrayList<T>& operator=(const ArrayList<T>& rhs);

    T& operator[] (int index)
    {
        while (index >= TotalSize)
            expand();

        return data[index];
    }

private:
    void expand();

    T* data;
    int TotalSize;
};

#include "ArrayList.cpp" // Including to avoid template classes linking errors

#endif // ARRAYLIST_H_INCLUDED
