#ifndef __NODE_H
#define __NODE_H

#include "Vertex.h"

class Node 
{
public:
	Vertex data;
	Node* next;

	Node();
	Node(const Vertex& data, Node* next = nullptr);
	Node(const Node& other) = delete;
	void insertAfter(Node* node);
	Node* deleteAfter();
	// Setters
	void setData(const Vertex& data);
	// Getters
	const Vertex& getData() const;
	Node* getNext() const;
};

#endif // __NODE_H