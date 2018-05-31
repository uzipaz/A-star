#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "ArrayList.h"
#include "ArrayList.cpp" // Including to avoid template classes linking errors

//template <class T>
class queue
{
public:
    queue();
    ~queue();

    void insert(int element);
    int remove();
    int removeFromBack();

    bool isEmpty();

    int returnAtFront();
    int returnAtBack();

    void emptyQueue();

private:
    ArrayList<int> data;

    int CurrentSize;
};

#endif // QUEUE_H_INCLUDED
