#ifndef __VERTEX_H
#define __VERTEX_H

#include "Utils.h"

class Vertex 
{
private:
	int x;
	int y;
	char data;

public:
	Vertex() = default;
	Vertex(int x, int y, char data);
	// Setters
	void setX(int x);
	void setY(int y);
	void setData(char data);
	// Getters
	int getX();
	int getY();
	char getData();
};

#endif // __VERTEX_H