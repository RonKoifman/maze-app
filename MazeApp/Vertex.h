#pragma once

#include "OutResources.h"

class Vertex {
private:
	int x;
	int y;
	char data;
public:
	Vertex();
	Vertex(int x, int y, char data);
	void showData();
	void printVertex();
	//setters
	bool setX(int x);
	bool setY(int y);
	bool setData(char data);
	//getters
	int getX();
	int getY();
	char getData();


};