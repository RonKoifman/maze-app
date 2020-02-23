#ifndef __STACK_H
#define __STACK_H

#include "Node.h"

// Implementation of stack as a linked list with pointers
class Stack
{
private:
	Node* topOfStack; // Pointer node to the top of the stack

public:
	Stack(); // C'tor
	Stack(const Stack& other) = delete; // Disable copy c'tor
	~Stack(); // D'tor
	void makeEmpty();
	bool isEmpty() const;
	void push(const Vertex& item);
	Vertex pop();
	const Vertex& top() const;
};

#endif // __STACK_H