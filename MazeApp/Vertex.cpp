#include "Vertex.h"

Vertex::Vertex() // Default C'tor
	: x(0), y(0), data('\0')
{
}

Vertex::Vertex(int x, int y, char data)
	: x(x), y(y), data(data) // C'tor
{
}

void Vertex::show()
{
	cout << "X = " << x << ", Y = " << y << ", Data = " << data << endl;
}

void Vertex::setX(int x)
{
	this->x = x;
}

void Vertex::setY(int y)
{
	this->y = y;
}

void Vertex::setData(char data)
{
	this->data = data;
}

int Vertex::getX()
{
	return x;
}

int Vertex::getY()
{
	return y;
}

char Vertex::getData()
{
	return data;
}