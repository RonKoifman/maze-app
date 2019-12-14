#include "Maze.h"

Maze::Maze(int rows, int columns, char ** maze)
	:maze(maze), rows(rows), columns(columns)
{
	readMaze();
}

Maze::Maze(int rows, int columns) // C'tor
	: maze(nullptr), rows(rows), columns(columns)
{
	if (rows % 2 == 1 && columns % 2 == 1) // Both rows and columns have to be odd numbers for valid random maze
	{
		setInitMaze();
		createRandomMaze();
	}
	else // Invalid input
	{
		cout << "Invalid input!" << endl;
		exit(INVALID_INPUT_ERROR);
	}
}

Maze::~Maze()
{
	for (int i = 0; i < rows; i++)
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
			cout << maze[i][j];
		}
		cout << endl;
	}
}

void Maze::readMaze()
{
	delete[] maze; // Free previous maze if exists

	maze = new char*[rows]; // Allocate maze all rows
	cin.ignore();
	for (int i = 0; i < rows; i++)
	{
		maze[i] = new char[columns + 1]; // Allocate maze each row
		cin.getline(maze[i], columns + 1); // Read each row to the maze
	}
}

void Maze::setInitMaze()
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

void Maze::createRandomMaze()
{
	Stack stack;
	Vertex vertex = Vertex(1, 1, FREE);
	Vertex neighbor;

	stack.makeEmpty(); // Make empty stack
	stack.push(vertex); // Initialize stack
	while (!stack.isEmpty())
	{
		vertex = stack.pop(); // Pop the first element
		maze[vertex.getX()][vertex.getY()] = PATH; // Mark visited vertices in maze
		vertex.setData(PATH); // Update vertex as visited
		
		if (checkNeighbors(vertex)) // Check for vertex neighbors
		{
			neighbor = getRandomNeighbor(vertex);
			removeWall(vertex, neighbor);
			stack.push(vertex);
			stack.push(neighbor);
		}
	}

	clearMaze();
}

Vertex Maze::getRandomNeighbor(Vertex vertex)
{
	Vertex neighbor;
	int x = vertex.getX(), y = vertex.getY();

	while (neighbor.getData() == '\0')
	{
		int direction = rand() % MAX_NEIGHBORS;

		switch ((Direction)direction)
		{
		case RIGHT:
		{
			if (y != (columns - 2) && maze[x][y + 2] == FREE) // Right neighbor
			{
				neighbor.setX(x);
				neighbor.setY(y + 2);
				neighbor.setData(FREE);
			}
			break;
		}
		case DOWN:
		{
			if (x != (rows - 2) && maze[x + 2][y] == FREE) // Bottom Neighbor
			{
				neighbor.setX(x + 2);
				neighbor.setY(y);
				neighbor.setData(FREE);
			}
			break;
		}
		case LEFT:
		{
			if (y != 1 && maze[x][y - 2] == FREE) // Left neighbor
			{
				neighbor.setX(x);
				neighbor.setY(y - 2);
				neighbor.setData(FREE);
			}
		}
		case UP:
		{
			if (x != 1 && maze[x - 2][y] == FREE) // Up neighbor
			{
				neighbor.setX(x - 2);
				neighbor.setY(y);
				neighbor.setData(FREE);
			}
			break;
		}
		}
	}

	return neighbor;
}

void Maze::solveMaze()
{
	Queue queue(rows * columns);
	Vertex startVertex(1, 0, maze[1][0]); // Starting vertex
	Vertex visitedVertex;
	bool isSolved = false;

	queue.enqueue(startVertex); // Initialize the queue with starting point (1,0)
	while (!queue.isEmpty() && !isSolved)
	{
		// Dequeue the head of the queue and mark it as visited
		visitedVertex = queue.dequeue();
		int vertexX = visitedVertex.getX();
		int vertexY = visitedVertex.getY();

		maze[vertexX][vertexY] = PATH; // Mark as visited
		if (maze[vertexX][vertexY] == maze[rows - 2][columns - 1]) // End point
		{
			isSolved = true; // Maze solved
		}
		else
		{
			addAllAccessibleNeighbors(visitedVertex, queue); // Add the accassible neighbors that were not visited
		}
	}
}

void Maze::addAllAccessibleNeighbors(Vertex visitedVertex, Queue& queue)
{
	Vertex neighbors[MAX_NEIGHBORS];
	int numOfNeighbors = 0;

	getNeighbors(visitedVertex, neighbors, numOfNeighbors); // Get unvisited neighbors
	for (int i = 0; i < numOfNeighbors; i++) // Enqueue unvisited neighbors
	{
		queue.enqueue(neighbors[i]);
	}
}

void Maze::getNeighbors(Vertex visitedVertex, Vertex neighbors[], int &numOfNeighbors)
{
	int x = visitedVertex.getX(), y = visitedVertex.getY();

	if (y != (columns - 1) && maze[x][y + 1] == FREE) // Check for right neighbor
	{
		Vertex rightNeighbor(x, y + 1, maze[x][y + 1]);
		neighbors[numOfNeighbors++] = rightNeighbor;
	}
	if (x != (rows - 1) && maze[x + 1][y] == FREE) // Check for bottom neighbor
	{
		Vertex bottomNeighbor(x + 1, y, maze[x + 1][y]);
		neighbors[numOfNeighbors++] = bottomNeighbor;
	}
	if (y != 1 && maze[x][y - 1] == FREE) // Check for left neighbor
	{
		Vertex leftNeighbor(x, y - 1, maze[x][y - 1]);
		neighbors[numOfNeighbors++] = leftNeighbor;
	}
	if (x != 1 && maze[x - 1][y] == FREE) // Check for up neighbor
	{
		Vertex upNeighbor(x - 1, y, maze[x - 1][y]);
		neighbors[numOfNeighbors++] = upNeighbor;
	}
}

void Maze::removeWall(Vertex& vertex, Vertex& neighbor)
{
	int neighborX = neighbor.getX(), vertexX = vertex.getX();
	int neighborY = neighbor.getY(), vertexY = vertex.getY();

	if (vertexX == neighborX) 
	{
		if (neighborY > vertexY) 
		{
			maze[vertexX][vertexY + 1] = FREE;
		}
		else
		{
			maze[vertexX][vertexY - 1] = FREE;
		}
	}
	else 
	{
		if (neighborX > vertexX) 
		{
			maze[vertexX + 1][vertexY] = FREE;
		}
		else 
		{
			maze[vertexX - 1][vertexY] = FREE;
		}
	}
}

void Maze::clearMaze()
{
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < columns; col++)
		{
			if (maze[row][col] == PATH) // Visited vertex
			{
				maze[row][col] = FREE;
			}
		}
	}
}

bool Maze::checkLine(string line, int row)
{
	int col;
	bool res = true;

	if (line.length() != columns) {
		res = false;
	}
	else {
		for (col = 0; col < columns; col++) {
			if (row == 0 || row == rows - 1) { // Upper & lower wall check.
				if (maze[row][col] != WALL) {
					res = false;
				}
			}
			else if (col == 0 || col == columns - 1) { // Side walls check.
				if ((row == 1  && col == 0) || (row == rows - 2  && col == columns - 1)) { //Entry and exit points.
					if (maze[row][col] != FREE)
						res = false;
				}
				else if (maze[row][col] != WALL) {
					res = false;
				}
			}
			else if (maze[row][col] != WALL || maze[row][col] != FREE) {
				res = false;
			}
		}
	}
	return res;
}

bool Maze::checkNeighbors(Vertex vertex)
{
	int x = vertex.getX(), y = vertex.getY();

	if (y != (columns - 2) && maze[x][y + 2] == FREE) // Check for right neighbor
	{
		return true;
	}
	else if (x != (rows - 2) && maze[x + 2][y] == FREE) // Check for bottom neighbor
	{
		return true;
	}
	else if (y != 1 && maze[x][y - 2] == FREE) // Check for left neighbor
	{
		return true;
	}
	else if (x != 1 && maze[x - 2][y] == FREE) // Check for up neighbor
	{
		return true;
	}
	else // No neighbors found
	{
		return false;
	}
}