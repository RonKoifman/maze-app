#pragma once


#include "OutResources.h";

class Node {
public:
	Vertex v;
	Node* next;

	Node(Node& other) = delete;
	Node(Vertex v, Node* next=nullptr);
	~Node();

	void insertAfter(Node *newnode);
	Node* deleteAfter();
	
	//setters
	bool setVertex(Vertex& v);
	//getters
	Vertex getVertex();
	Node* getNext();

};

