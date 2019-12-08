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
	int size;
public:
	Queue(int size); // C'tor
	Queue(Queue& other) = delete; // Disable copy c'tor
	~Queue(); // D'tor
	void makeEmpty();
	bool isEmpty();
	Vertex front();
	void enqueue(Vertex vertex);
	Vertex dequeue();
private:
	int addOne(int index);
};

#endif // __QUEUE_H