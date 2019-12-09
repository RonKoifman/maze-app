#ifndef __MAZE_H
#define __MAZE_H

#include "OutResources.h"
#include "Stack.h"
#include "Queue.h"

class Maze
{
private:
	char** maze;
	int rows;
	int columns;
public:
	Maze(int rows, int columns, char** maze = nullptr); // C'tor
	Maze(Maze& other) = delete; // Disable copy c'tor
	~Maze(); // D'tor
	void show();
	// Setters
	void setMaze(char** maze, int rows, int columns);
	void setInitMaze(int rows, int columns);
	void setRows(int rows);
	void setColumns(int columns);
	// Getters
	char** getMaze();
	int getRows() const;
	int getColumns() const;

private:
	// Private functions
	void createRandomMaze(int rows, int columns);
	bool checkNeighbors(char** maze, Vertex vertex);
	Vertex getRandomNeighbor(char** maze, Vertex vertex);
	void removeWall(Vertex& vertex, Vertex& neighbor);
	void clearMaze();
	
};

#endif // __MAZE_H