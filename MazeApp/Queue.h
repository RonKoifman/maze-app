#ifndef __QUEUE_H
#define __QUEUE_H

#include "OutResources.h"
#include "Vertex.h"

class Queue
{
private:
	int head;
	int tail;
	Vertex* data;
	int currSize;
	int maxSize;

public:
	Queue(int maxSize); // C'tor
	Queue(Queue& other) = delete; // Disable copy c'tor
	~Queue(); // D'tor
	void makeEmpty();
	bool isEmpty();
	Vertex front();
	void enqueue(const Vertex& vertex);
	Vertex dequeue();
	// Friend functions
	friend void freeAllocatedQueue(Queue& queue);
	friend bool isNeighborExists(Queue& queue, Vertex& neighbor);

private:
	int addOne(int index);
};

#endif // __QUEUE_H