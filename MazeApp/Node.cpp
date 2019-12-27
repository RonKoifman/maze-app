#include "Node.h"

Node::Node() // C'tor
	: next(nullptr)
{
}

Node::Node(const Vertex& vertex, Node* next) // Copy C'tor
	: vertex(vertex), next(next)
{
}

void Node::insertAfter(Node* newNode) // Insert new node after current node
{
	newNode->next = next;
	next = newNode;
}

Node* Node::deleteAfter() // Delete node after current node
{
	Node* temp = next;
	if (next == nullptr) // End of the list
	{
		return nullptr;
	}

	next = temp->next;
	return temp;
}

void Node::setVertex(const Vertex& vertex)
{
	this->vertex = vertex;
}

Vertex Node::getVertex() const
{
	return vertex;
}

Node* Node::getNext() const
{
	return next;
}