#ifndef PRIORITYQUEUE_CPP_INCLUDED
#define PRIORITYQUEUE_CPP_INCLUDED

#include "PriorityQueue.h"

template <class T>
PriorityQueue<T>::PriorityQueue()
{
    NoOfElements = 0;
}

template <class T>
PriorityQueue<T>::~PriorityQueue()
{
    // Do nothing
}

template <class T>
void PriorityQueue<T>::insert(int key, T value)
{
    data[++NoOfElements].key = key;
	data[NoOfElements].value = value;

	int child = NoOfElements, parent = child / 2;

	while (parent > 0 && data[parent].value > data[child].value)
	{
		swap(data[parent], data[child]);

		child = parent;
		parent = child / 2;
	}
}

template <class T>
int PriorityQueue<T>::remove()
{
    int return_value = data[1].key;
	data[1] = data[NoOfElements--];

	int parent = 1, child = 2 * parent;

	while (child <= NoOfElements)
	{
		if (data[child + 1].value < data[child].value)
            child++;

		if (data[parent].value > data[child].value)
			swap(data[parent], data[child]);

		parent = child;
		child = 2 * parent;
	}

	return return_value;
}

template <class T>
bool PriorityQueue<T>::isEmpty()
{
    return (NoOfElements == 0);
}

#endif
