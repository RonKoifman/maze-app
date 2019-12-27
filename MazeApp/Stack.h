#ifndef __STACK_H
#define __STACK_H

#include "OutResources.h"
#include "Node.h"

class Stack
{
private:
	Node* topOfStack;

public:
	Stack(); // C'tor
	Stack(Stack& other) = delete; // Disable copy c'tor
	~Stack(); // D'tor
	void makeEmpty();
	bool isEmpty();
	void push(const Vertex& vertex);
	Vertex pop();
	Vertex top();
};

#endif // __STACK_H