#include "Node.h"

Node::Node() // C'tor
	: next(nullptr)
{
}

Node::Node(Vertex vertex, Node* next) // Copy C'tor
	: vertex(vertex), next(next)
{
}

void Node::insertAfter(Node* newNode)
{
	newNode->next = next;
	next = newNode;
}

Node* Node::deleteAfter()
{
	Node* temp = next;
	if (next == nullptr) // End of the list
	{
		return nullptr;
	}

	next = temp->next;
	return temp;
}

void Node::setVertex(Vertex vertex)
{
	this->vertex = vertex;
}

Vertex Node::getVertex()
{
	return vertex;
}

Node* Node::getNext()
{
	return next;
}