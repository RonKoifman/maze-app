#include "Node.h"

Node::Node() // Default C'tor
	: data(), next(nullptr)
{
}

Node::Node(const Vertex& data, Node* next) // C'tor
	: data(data), next(next)
{
}

// Insert new node after current node
void Node::insertAfter(Node* newNode)
{
	newNode->next = this->next;
	this->next = newNode;
}

// Delete node after current node
Node* Node::deleteAfter()
{
	Node* temp = this->next;

	if (this->next == nullptr) // End of the list
	{
		return nullptr;
	}

	this->next = temp->next;
	return temp;
}

void Node::setData(const Vertex& data)
{
	this->data = data;
}

const Vertex& Node::getData() const
{
	return data;
}

Node* Node::getNext() const
{
	return next;
}