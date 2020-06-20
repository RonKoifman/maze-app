#include "Queue.h"

Queue::Queue(int maxSize)
	: maxSize(maxSize)
{
	data = new Vertex[maxSize];
	makeEmpty();
}

Queue::~Queue()
{
	delete[] data;
}

// Make an empty queue
void Queue::makeEmpty()
{
	head = 1;
	tail = 0;
	currSize = 0;
}

// Check if queue is empty
bool Queue::isEmpty() const
{
	return (addOne(tail) == head);
}

// Return the data of the first item in queue
const Vertex& Queue::front() const
{
	if (isEmpty())
	{
		cout << "Error: Queue is empty!" << endl;
		exit(EMPTY_QUE_ERROR);
	}

	return data[head];
}

// Add item to the end of queue
void Queue::enqueue(const Vertex& item)
{
	if (addOne(addOne(tail)) == head)
	{
		cout << "Error: Queue is full!" << endl;
		exit(FULL_QUE_ERROR);
	}

	tail = addOne(tail);
	data[tail] = item;
	currSize++;
}

// Remove first item in queue and return it
Vertex Queue::dequeue()
{
	Vertex item = data[head];

	head = addOne(head);
	currSize--;

	return item;
}

// Add one to index in a cyclic way
int Queue::addOne(int index) const
{
	return (1 + index) % maxSize;
}

int Queue::getCurrSize() const
{
	return currSize;
}

void Queue::freeAllocatedData()
{
	delete[] data;
}