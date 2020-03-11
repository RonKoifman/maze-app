#ifndef __MAZE_H
#define __MAZE_H

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
	Maze(); // C'tor
	Maze(Maze& other) = delete; // Disable copy c'tor
	~Maze(); // D'tor
	void runProgram();
	void show() const;
	void solve();
	// Setters
	void setUserMaze();
	void setRandomMaze();
	void setRowsAndColumns(int rows, int columns);
	// Getters
	char** getMaze() const;
	int getRows() const;
	int getColumns() const;

// Private functions
private:
	void initMaze();
	void createRandomMaze();
	void getNeighbors(Vertex& visitedVertex, const int neighborDistance, Vertex neighbors[], int& numOfNeighbors) const;
	bool isNeighborExists(Queue& queue, Vertex& neighbor) const;
	void freeAllocatedQueue(Queue& queue);
	const Vertex& getRandomNeighbor(Vertex neighbors[], int numOfNeighbors) const;
	void addAllAccessibleNeighbors(Vertex& visitedVertex, Queue& queue);
	void removeWall(Vertex& vertex, Vertex& neighbor);
	void clearMaze();
	void freeAllocatedMaze(int allocatedRows);
	bool checkLine(char* line, int currRow);
};

#endif // __MAZE_H