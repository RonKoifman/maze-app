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
	Maze(int rows, int columns); // C'tor
	Maze(Maze& other) = delete; // Disable copy c'tor
	~Maze(); // D'tor
	void show();
	void solve();
	// Setters
	void setUserMaze();
	void setRandomMaze();
	void setRows(int rows);
	void setColumns(int columns);
	// Getters
	char** getMaze() const;
	int getRows() const;
	int getColumns() const;

private:
	// Private functions
	void initMaze();
	void createRandomMaze();
	void getNeighbors(Vertex& visitedVertex, const int neighborDistance, Vertex neighbors[], int& numOfNeighbors);
	Vertex getRandomNeighbor(Vertex neighbors[], int numOfNeighbors);
	void addAllAccessibleNeighbors(Vertex& visitedVertex, Queue& queue);
	void removeWall(Vertex& vertex, Vertex& neighbor);
	void clearMaze();
	void freeAllocatedMaze(int allocatedRows);
	bool checkLine(char* line, int currRow);
};

#endif // __MAZE_H