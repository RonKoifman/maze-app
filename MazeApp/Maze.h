#ifndef __MAZE_H
#define __MAZE_H

#include "OutResources.h"
#include "Stack.h"
#include "Queue.h"

const int MAX_NEIGHBORS = 4;

class Maze
{
private:
	char** maze;
	int rows;
	int columns;
public:
	enum Direction
	{
		RIGHT, DOWN, LEFT, UP
	};
	Maze(int rows, int columns, char** maze); // C'tor
	Maze(int rows, int columns); // C'tor
	Maze(Maze& other) = delete; // Disable copy c'tor
	~Maze(); // D'tor
	void show();
	void solveMaze();
	// Setters
	void setInitMaze();
	void setRows(int rows);
	void setColumns(int columns);
	// Getters
	char** getMaze();
	int getRows() const;
	int getColumns() const;
	void readMaze();

private:
	// Private functions
	void createRandomMaze();
	void getNeighbors(Vertex vertex, Vertex neighbors[], int &numOfNeighbors);
	bool checkNeighbors(Vertex vertex);
	Vertex getRandomNeighbor(Vertex vertex);
	// void solveMaze();
	void addAllAccessibleNeighbors(Vertex visitedVertex, Queue& queue);
	void removeWall(Vertex& vertex, Vertex& neighbor);
	void clearMaze();
	bool checkLine(string line, int row);
};

#endif // __MAZE_H