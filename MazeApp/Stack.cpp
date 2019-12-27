#include "Stack.h"

Stack::Stack() // C'tor
	: topOfStack(nullptr)
{
}

Stack::~Stack() // D'tor
{
	makeEmpty();
}

void Stack::makeEmpty() // Make an empty stack
{
	Node* temp;
	while (topOfStack != nullptr)
	{
		temp = topOfStack;
		topOfStack = topOfStack->next;
		delete temp;
	}
}

bool Stack::isEmpty() // Check if stack is empty
{
	return (topOfStack == nullptr);
}

void Stack::push(const Vertex& vertex) // Push item into the stack
{
	topOfStack = new Node(vertex, topOfStack);
}

Vertex Stack::pop() // Pop top item and return it
{
	if (isEmpty()) 
	{
		cout << "Error: stack is empty!" << endl;
		exit(EMPTY_STACK_ERROR);
	}
	Node* temp = topOfStack;
	Vertex vertex = topOfStack->getVertex();
	topOfStack = topOfStack->next;

	delete temp;
	return vertex;
}

Vertex Stack::top() // Return the data of the top item in the stack
{
	return topOfStack->getVertex();
}