#include "Maze.h"

Maze::Maze(int rows, int columns) // C'tor
	: maze(nullptr), rows(rows), columns(columns)
{
}

Maze::~Maze() // D'tor
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

bool Maze::checkLine(char* line, int currRow)
{
	if (strlen(line) != columns) // Invalid line length
	{
		return false;
	}
	
	for (int col = 0; col < columns; col++)
	{
		if (currRow == 0 || currRow == rows - 1)
		{
			if (maze[currRow][col] != WALL) // Upper and lower wall check
			{
				return false;
			}
		}
		else if (col == 0 || col == columns - 1)
		{
			if ((currRow == 1 && col == 0) || (currRow == rows - 2 && col == columns - 1))
			{
				if (maze[currRow][col] != FREE) // Entry and exit points check
				{
					return false;
				}
			}
			else if (maze[currRow][col] != WALL) // Side walls check
			{
				return false;
			}
		}
		else if (maze[currRow][col] != WALL && maze[currRow][col] != FREE) // Characters check
		{
			return false;
		}
	}

	return true;
}


void Maze::setUserMaze()
{
	maze = new char*[rows]; // Allocate all maze rows
	cin.ignore();
	for (int i = 0; i < rows; i++)
	{
		maze[i] = new char[columns + 1]; // Allocate each maze row
		cin.getline(maze[i], columns + 1); // Read row

		if (!checkLine(maze[i], i)) // Input validation
		{
			freeAllocatedMaze(i); // Free the allocated rows before exit
			cout << "invalid input" << endl;
			exit(INVALID_INPUT_ERROR);
		}
	}
}

void Maze::freeAllocatedMaze(int allocatedRows)
{
	for (int i = 0; i < allocatedRows; i++)
	{
		delete[] maze[i];
	}

	delete[] maze;
}

void Maze::setRandomMaze()
{
	// Both rows and columns have to be odd numbers different than 1 for valid random maze
	// (because we initialize the stack with the vertex (1,1))
	if (rows % 2 == 1 && columns % 2 == 1 && rows != 1 && columns != 1) 
	{
		initMaze();
		createRandomMaze();
	}
	else
	{
		cout << "invalid input" << endl;
		exit(INVALID_INPUT_ERROR);
	}
}

void Maze::setRows(int rows)
{
	this->rows = rows;
}

void Maze::setColumns(int columns)
{
	this->columns = columns;
}

char** Maze::getMaze() const
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

void Maze::initMaze()
{
	int row, col;

	maze = new char*[rows]; // Allocate all maze rows

	for (row = 0; row < rows; row++)
	{
		maze[row] = new char[columns + 1]; // Allocate each maze row

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

void Maze::createRandomMaze()
{
	Stack stack;
	Vertex neighbor, neighbors[MAX_NEIGHBORS];
	int numOfNeighbors;
	Vertex vertex(1, 1, FREE); // Starting vertex

	stack.makeEmpty(); // Make empty stack
	stack.push(vertex); // Initialize stack
	while (!stack.isEmpty())
	{
		numOfNeighbors = 0; // Initialize number of unvisited neighbors
		vertex = stack.pop(); // Pop the first element
		maze[vertex.getX()][vertex.getY()] = PATH; // Mark visited vertex in the maze
		getNeighbors(vertex, 2, neighbors, numOfNeighbors); // Check for vertex unvisited neighbors

		if (numOfNeighbors > 0) // At least one unvisited neighbor
		{
			neighbor = getRandomNeighbor(neighbors, numOfNeighbors);
			removeWall(vertex, neighbor);
			stack.push(vertex);
			stack.push(neighbor);
		}
	}

	clearMaze();
}

Vertex Maze::getRandomNeighbor(Vertex neighbors[], int numOfNeighbors)
{
	int index = rand() % numOfNeighbors;

	return neighbors[index]; // Random neighbor
}

void Maze::solve()
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
			addAllAccessibleNeighbors(visitedVertex, queue); // Add the accessible neighbors that were not visited
		}
	}
}

void Maze::addAllAccessibleNeighbors(Vertex &visitedVertex, Queue& queue)
{
	Vertex neighbors[MAX_NEIGHBORS];
	int numOfNeighbors = 0;

	getNeighbors(visitedVertex, 1, neighbors, numOfNeighbors); // Get unvisited neighbors
	for (int i = 0; i < numOfNeighbors; i++) // Enqueue unvisited neighbors
	{
		// To avoid duplicates add to the queue only neighbors that not exist already
		// Note: Of course, this check is not so efficient but it is inevitable in an extreme case when the user inserts
		// a large array with only walls around which causes the queue to reach its full capacity because of duplicates
		if (!isNeighborExists(queue, neighbors[i])) 
		{
			queue.enqueue(neighbors[i]);
		}
	}

	if (numOfNeighbors == 0 && queue.isEmpty()) // No solution
	{
		freeAllocatedQueue(queue); // Free the queue before exit
		freeAllocatedMaze(rows); // Free the maze before exit
		cout << "no solution" << endl;
		exit(NO_SOLUTION_ERROR);
	}
}

void Maze::getNeighbors(Vertex& visitedVertex, const int neighborDistance, Vertex neighbors[], int& numOfNeighbors)
{
	int x = visitedVertex.getX(), y = visitedVertex.getY();

	if (y != (columns - neighborDistance) && maze[x][y + neighborDistance] == FREE) // Check for right neighbor
	{
		Vertex rightNeighbor(x, y + neighborDistance, maze[x][y + neighborDistance]);
		neighbors[numOfNeighbors++] = rightNeighbor;
	}
	if (x != (rows - neighborDistance) && maze[x + neighborDistance][y] == FREE) // Check for bottom neighbor
	{
		Vertex bottomNeighbor(x + neighborDistance, y, maze[x + neighborDistance][y]);
		neighbors[numOfNeighbors++] = bottomNeighbor;
	}
	if (y != 1 && maze[x][y - neighborDistance] == FREE) // Check for left neighbor
	{
		Vertex leftNeighbor(x, y - neighborDistance, maze[x][y - neighborDistance]);
		neighbors[numOfNeighbors++] = leftNeighbor;
	}
	if (x != 1 && maze[x - neighborDistance][y] == FREE) // Check for up neighbor
	{
		Vertex upNeighbor(x - neighborDistance, y, maze[x - neighborDistance][y]);
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

void freeAllocatedQueue(Queue& queue)
{
	delete[] queue.data;
}

bool isNeighborExists(Queue& queue, Vertex& neighbor)
{
	bool isExists = false;

	// Loop through the queue and check if neighbor exists
	for (int i = 0; i < queue.currSize; i++)
	{
		Vertex vertex = queue.dequeue();
		if (vertex.getX() == neighbor.getX() && vertex.getY() == neighbor.getY()) // Neighbor exists
		{
			isExists = true;
		}
		queue.enqueue(vertex); // Need to enqueue back all queue elements to retain the order
	}

	return isExists;
}