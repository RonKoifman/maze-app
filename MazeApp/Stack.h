#pragma once


#include "OutResources.h"
#include "Node.h"

class Stack {
private:
	Node* top;

public:
	Stack();
	~Stack();
	void makeEmpty();
	bool isEmpty();
	void Push(Vertex& v);
	Vertex Pop();
	Vertex Top();
};