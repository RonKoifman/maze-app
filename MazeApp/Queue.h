#ifndef __QUEUE_H
#define __QUEUE_H

#include "Vertex.h"

// Implementation of queue as a cyclic array
class Queue
{
private:
	int head; // Beginning of queue
	int tail; // End of queue
	Vertex* data; // Data array
	int currSize; // Current size of queue
	int maxSize; // Maximum capacity of queue

public:
	Queue(int maxSize);
	Queue(const Queue& other) = delete;
	~Queue();
	void makeEmpty();
	bool isEmpty() const;
	const Vertex& front() const;
	void enqueue(const Vertex& item);
	Vertex dequeue();
	int getCurrSize() const;
	void freeAllocatedData();

// Private functions
private:
	int addOne(int index) const;
};

#endif // __QUEUE_H