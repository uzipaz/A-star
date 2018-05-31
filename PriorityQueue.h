#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

#include "ArrayList.h"

#include "miscellaneous.h"

template <class T>
class PriorityQueue
{
public:
    PriorityQueue();
    ~PriorityQueue();

    void insert(int element, T value);
    int remove();

    bool isEmpty();

private:
    struct node
    {
        int key;
        T value;
    };

	ArrayList<node> data;
	int NoOfElements;
};

#include "PriorityQueue.cpp" // Including to avoid template classes linking errors

#endif // PRIORITYQUEUE_H_INCLUDED
