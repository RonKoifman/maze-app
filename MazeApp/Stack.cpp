#include "Stack.h"

Stack::Stack()
	: topOfStack(nullptr)
{
}

Stack::~Stack()
{
	makeEmpty();
}

// Make an empty stack
void Stack::makeEmpty()
{
	Node* temp;

	while (topOfStack != nullptr)
	{
		temp = topOfStack;
		topOfStack = topOfStack->next;
		delete temp;
	}
}

// Check if stack is empty
bool Stack::isEmpty() const
{
	return (topOfStack == nullptr);
}

// Push item into the stack
void Stack::push(const Vertex& item)
{
	topOfStack = new Node(item, topOfStack);
}

// Pop top item and return it
Vertex Stack::pop()
{
	if (isEmpty()) 
	{
		cout << "Error: Stack is empty!" << endl;
		exit(EMPTY_STACK_ERROR);
	}

	Node* temp = topOfStack;
	Vertex data = topOfStack->getData();
	topOfStack = topOfStack->next;

	delete temp;
	return data;
}

// Return the data of the top item in the stack
const Vertex& Stack::top() const
{
	if (isEmpty())
	{
		cout << "Error: Stack is empty!" << endl;
		exit(EMPTY_STACK_ERROR);
	}

	return topOfStack->getData();
}