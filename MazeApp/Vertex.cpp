#include "Vertex.h"

Vertex::Vertex() : x(0), y(0), data('\0')
{
}

Vertex::Vertex(int x, int y, char data) : x(x), y(y), data(data)
{
}

void Vertex::showData()
{
	cout << data;
}

void Vertex::printVertex()
{
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
	cout << "Data: " << data << endl;
}

bool Vertex::setX(int x)
{
	Vertex::x = x;
	return true;
}

bool Vertex::setY(int y)
{
	Vertex::y = y;
	return true;
}

bool Vertex::setData(char data)
{
	Vertex::data = data;
	return true;
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
