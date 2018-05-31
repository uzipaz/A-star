#include "queue.h"

//template <class T>
queue::queue()
{
    CurrentSize = 0;
}

//template <class T>
void queue::insert(int element)
{
    data[CurrentSize++] = element;
}

//template <class T>
int queue::remove()
{
    if (!isEmpty())
    {
        int return_var = data[0];

        for (int i = 1; i < CurrentSize; i++)
        {
            data[i - 1] = data[i];
        }

        if (CurrentSize > 0)
            CurrentSize--;

        return return_var;
    }

    return -1;
}

int queue::removeFromBack()
{
    return data[--CurrentSize];
}

//template <class T>
bool queue::isEmpty()
{
    return (CurrentSize == 0);
}

void queue::emptyQueue()
{
    CurrentSize = 0;
}

//template <class T>
int queue::returnAtFront()
{
    return data[0];
}

//template <class T>
int queue::returnAtBack()
{
    return data[CurrentSize - 1];
}

//template <class T>
queue::~queue()
{
    //delete [] data;
}


//template class queue<int>;

