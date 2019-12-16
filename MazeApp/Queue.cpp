#include "Queue.h"

Queue::Queue(int phySize) // C'tor
	: phySize(phySize)
{
	data = new Vertex[phySize];
	makeEmpty();
}

Queue::~Queue() // D'tor
{
	delete[] data;
}

void Queue::makeEmpty() // Make an empty queue
{
	head = 1;
	tail = 0;
	logSize = 0;
}

bool Queue::isEmpty() // Check if the queue is empty
{
	return (addOne(tail) == head);
}

Vertex Queue::front() // Return the data of the first item in the queue
{
	if (isEmpty())
	{
		cout << "Error: queue is empty!" << endl;
		exit(EMPTY_QUE_ERROR);
	}
	return data[head];
}

void Queue::enqueue(Vertex& vertex) // Add item to the end of the queue
{
	if (addOne(addOne(tail)) == head)
	{
		cout << "Error: queue is full!" << endl;
		exit(FULL_QUE_ERROR);
	}
	tail = addOne(tail);
	data[tail] = vertex;
	logSize++;
}

Vertex Queue::dequeue() // Remove first item in the queue and return it
{
	Vertex vertex = data[head];
	head = addOne(head);
	logSize--;
	return vertex;
}

int Queue::addOne(int index) // Add one to index in a cyclic way
{
	return (1 + index) % phySize;
}