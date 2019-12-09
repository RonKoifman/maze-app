#include "Maze.h"

Maze::Maze(int rows, int columns, char** maze) // C'tor
	: maze(nullptr)
{
	setRows(rows);
	setColumns(columns);

	if (maze) // Set user's maze
	{
		setMaze(maze, rows, columns);
	}
	else // Initialize maze and create random maze
	{
		if (rows % 2 == 1 && columns % 2 == 1) // Both rows and columns have to be odd numbers for valid random maze
		{
			setInitMaze(rows, columns);
			createRandomMaze(rows, columns);
		}
		else // Invalid input
		{
			cout << "Invalid input!" << endl;
			exit(INVALID_INPUT_ERROR);
		}
	}
}

Maze::~Maze()
{
	for (int i = 0; i < columns; i++)
	{
		delete[] maze[i];
	}

	delete[] maze;
}

void Maze::show()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
}

void Maze::setMaze(char** maze, int rows, int columns)
{
	delete[] maze; // Free previous maze if exists

	this->maze = new char*[rows]; // Allocate maze rows
	for (int i = 0; i < rows; i++)
	{
		this->maze[i] = new char[columns + 1]; // Allocate maze columns
		strcpy(this->maze[i], maze[i]); // Copy each row from the given maze to the current maze
	}
}

void Maze::setInitMaze(int rows, int columns)
{
	int row, col;
	maze = new char*[rows]; // Allocate maze rows

	for (row = 0; row < rows; row++)
	{
		maze[row] = new char[columns + 1]; // Allocate each maze column

		if (row % 2 == 0) // Even rows
		{
			for (col = 0; col < columns; col++)
			{
				maze[row][col] = WALL;
			}
		}
		else // Odd rows
		{
			for (col = 0; col < columns; col++)
			{
				if (col % 2 == 0)
				{
					maze[row][col] = WALL;
				}
				else
				{
					maze[row][col] = FREE;
				}
			}
		}
		maze[row][col] = '\0';
	}

	// Set entrance to maze and exit from maze
	maze[1][0] = FREE;
	maze[rows - 2][columns - 1] = FREE;
}

void Maze::setRows(int rows)
{
	this->rows = rows;
}

void Maze::setColumns(int columns)
{
	this->columns = columns;
}

char** Maze::getMaze()
{
	return maze;
}

int Maze::getRows() const
{
	return rows;
}

int Maze::getColumns() const
{
	return columns;
}

void Maze::createRandomMaze(int rows, int columns)
{
	Stack stack;
	Vertex vertex(1, 1, ' ');
	Vertex neighbor;

	stack.makeEmpty();
	stack.push(vertex);
	while (!stack.isEmpty())
	{
		vertex = stack.pop();
		maze[vertex.getX()][vertex.getY()] = '$';
		vertex.setData('$');

		if (checkNeighbors(maze, vertex))
		{
			neighbor = getRandomNeighbor(maze, vertex);
			removeWall(vertex, neighbor);
			stack.push(vertex);
			stack.push(neighbor);
		}
	}
	show();
	cout << endl;
	clearMaze();
}

bool Maze::checkNeighbors(char** maze, Vertex vertex)
{
	int vertexX = vertex.getX(), vertexY = vertex.getY();

	if (vertexY != (columns - 2) && maze[vertexX][vertexY + 2] != WALL && maze[vertexX][vertexY + 2] != PATH) // Right
	{
		return true;
	}
	else if (vertexX != (rows - 2) && maze[vertexX + 2][vertexY] != WALL && maze[vertexX + 2][vertexY] != PATH) // Down
	{
		return true;
	}
	else if (vertexY != 1 && maze[vertexX][vertexY - 2] != WALL && maze[vertexX][vertexY - 2] != PATH) // Left
	{
		return true;
	}
	else if (vertexX != 1 && maze[vertexX - 2][vertexY] != WALL && maze[vertexX - 2][vertexY] != PATH) // Up
	{
		return true;
	}
	else
	{
		return false;
	}
}

Vertex Maze::getRandomNeighbor(char** maze, Vertex vertex)
{
	Vertex neighbor;
	int vertexX = vertex.getX(), vertexY = vertex.getY();


	while (neighbor.getData() == '\0') 
	{
		//srand((unsigned)time(NULL));
		int i = rand() % 4;

		switch (i)
		{
		case RIGHT:
		{
			if (vertexY != (columns - 2) && maze[vertexX][vertexY + 2] != WALL && maze[vertexX][vertexY + 2] != PATH) // Right
			{
				neighbor.setX(vertexX);
				neighbor.setY(vertexY + 2);
				neighbor.setData(FREE);
			}
			break;
		}
		case DOWN:
		{
			if (vertexX != (rows - 2) && maze[vertexX + 2][vertexY] != WALL && maze[vertexX + 2][vertexY] != PATH) // Down
			{
				neighbor.setX(vertexX + 2);
				neighbor.setY(vertexY);
				neighbor.setData(FREE);
			}
			break;
		}
		case LEFT:
		{
			if (vertexY != 1 && maze[vertexX][vertexY - 2] != WALL && maze[vertexX][vertexY - 2] != PATH) // Left
			{
				neighbor.setX(vertexX);
				neighbor.setY(vertexY - 2);
				neighbor.setData(FREE);
			}
		}
		case UP:
		{
			if (vertexX != 1 && maze[vertexX - 2][vertexY] != WALL && maze[vertexX - 2][vertexY] != PATH) // Up
			{
				neighbor.setX(vertexX - 2);
				neighbor.setY(vertexY);
				neighbor.setData(FREE);
			}
			break;
		}
		}
	}

	return neighbor;
}

void Maze::removeWall(Vertex& vertex, Vertex& neighbor)
{
	int neighborX = neighbor.getX(), vertexX = vertex.getX();
	int neighborY = neighbor.getY(), vertexY = vertex.getY();
	if (vertex.getX() == neighbor.getX()) {
		if (neighborY > vertexY) {
			maze[vertexX][vertexY + 1] = ' ';
		}
		else {
			maze[vertexX][vertexY - 1] = ' ';
		}
	}
	else {
		if (neighborX > vertexX) {
			maze[vertexX + 1][vertexY] = ' ';
		}
		else {
			maze[vertexX - 1][vertexY] = ' ';
		}
	}
}

void Maze::clearMaze()
{
	int row, col;
	for (row = 0; row < rows; row++)
	{
		for (col = 0; col < columns; col++)
		{
			if (maze[row][col] == PATH) {
				maze[row][col] = FREE;
			}
		}

	}
}