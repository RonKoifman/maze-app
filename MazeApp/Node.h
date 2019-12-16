#ifndef __NODE_H
#define __NODE_H

#include "OutResources.h"
#include "Vertex.h"

class Node 
{
public:
	Vertex vertex;
	Node* next;

	Node(); // C'tor
	Node(Vertex& vertex, Node* next = nullptr); // Copy C'tor
	Node(Node& other) = delete; // Disable default copy c'tor
	void insertAfter(Node* node);
	Node* deleteAfter();
	// Setters
	void setVertex(Vertex& vertex);
	// Getters
	Vertex getVertex();
	Node* getNext();
};

#endif // __NODE_H