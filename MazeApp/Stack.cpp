#include "Stack.h"

Stack::Stack()
{
	top = nullptr;
}

Stack::~Stack()
{
	makeEmpty();
}

void Stack::makeEmpty()
{
	Node* temp;
	while (top != nullptr) {
		temp = top;
		top = top->next;
		delete temp;
	}
}

bool Stack::isEmpty()
{
	return (top == nullptr);
}

void Stack::Push(Vertex& v)
{
	top = new Node(v, top);
}
Vertex Stack::Pop()
{
	if (isEmpty()) {
		cout << "ERROR: Stack is Empty can't pop." << endl;
		exit(1);
	}
	Node* temp = top;
	Vertex res = top->getVertex();
	top = top->next;
	delete temp;
	return res;
}

Vertex Stack::Top()
{
	return top->v;
}
