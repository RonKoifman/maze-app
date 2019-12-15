#ifndef __MAZE_H
#define __MAZE_H

#include "OutResources.h"
#include "Stack.h"
#include "Queue.h"

const int MAX_NEIGHBORS = 3;

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

	Maze(int rows, int columns); // C'tor
	Maze(Maze& other) = delete; // Disable copy c'tor
	~Maze(); // D'tor
	void show();
	void solveMaze();
	// Setters
	void setUserMaze();
	void setRandomMaze();
	void setRows(int rows);
	void setColumns(int columns);
	// Getters
	char** getMaze();
	int getRows() const;
	int getColumns() const;

private:
	// Private functions
	void initMaze();
	void createRandomMaze();
	void getNeighbors(Vertex vertex, Vertex neighbors[], int &numOfNeighbors);
	bool checkNeighbors(Vertex vertex);
	Vertex getRandomNeighbor(Vertex vertex);
	void addAllAccessibleNeighbors(Vertex visitedVertex, Queue& queue);
	void removeWall(Vertex& vertex, Vertex& neighbor);
	void clearMaze();
	void freeAllocatedMaze(int allocatedRows);
	bool checkLine(char* line, int currRow);
};

#endif // __MAZE_H