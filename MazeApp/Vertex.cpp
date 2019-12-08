#include "Vertex.h"

Vertex::Vertex(int x, int y, char data) : x(x), y(y), data(data)
{
}

bool Vertex::setX(int x)
{
	Vertex::x = x;
}

bool Vertex::setY(int y)
{
	Vertex::y = y;
}

bool Vertex::setData(char data)
{
	Vertex::data = data;
}

int Vertex::getX()
{
	return Vertex::x;
}

int Vertex::getY()
{
	return Vertex::y;
}

char Vertex::getData()
{
	return Vertex::data;
}
