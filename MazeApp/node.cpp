#include "Node.h"



Node::Node(Vertex v, Node* next) : v(v)
{
	Node::next = next;
}

Node::~Node()
{
	next = nullptr;
}

void Node::insertAfter(Node* newnode)
{
	newnode->next = next;
	Node::next = newnode;
}

Node* Node::deleteAfter()
{
	Node* temp = next;
	if (next == nullptr) return nullptr;
	next = temp->next;
	return temp;
}

bool Node::setVertex(Vertex& v)
{
	Node::v = v;
	return true;
}


Vertex Node::getVertex()
{
	return Node::v;
}

Node* Node::getNext()
{
	return Node::next;
}
