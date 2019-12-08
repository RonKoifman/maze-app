#include "OutResources.h"
#include "Stack.h"


int main()
{
	Stack s;
	int i;
	cout << "Enter vertex data: ";
	char c;
	cin >> c;
	Vertex v;
	while (c != '$') {
		v = Vertex(int(c), int(c), c);
		s.Push(v);
		v.showData();
		cout << endl;
		cout << "\nEnter vertex data: ";
		cin >> c;
	}
	while (!s.isEmpty()) {
		s.Pop().showData();
		cout << endl;
	}
}



void createMaze(int row, int columns) 
{
	Maze maze(rows, columns);
	maze.setDefault();
	Stack s;
	s.makeEmpty();
	Vertex v = Vertex(1, 1, ' '), neighbor;
	
	s.Push(v);
	while (!s.isEmpty()) {
		v = s.Pop();
		maze.maze[v.getX()][v.getY] = '$';
		v.setData('$');
		if (checkNeighbors(maze, v)) {
			neighbor = getRandomNeighbor(maze, v);
			removeWall(v, neighbor);
			s.Push(v);
			s.Push(neighbor);
		}
	}
	clearMaze(maze);
}

bool checkNeighbors(Maze maze, Vertex v) 
{
	bool res;

	if (v.getY() != (maze.getColumns() - 2) && maze.maze[v.getX()][v.getY() + 2] != '*' && maze.maze[v.getX()][v.getY() + 2] != '$') //right
	{
		res = true;
	}
	else if (v.getX() != (maze.getRows() - 2) && maze.maze[v.getX() + 2][v.getY()] != '*' && maze.maze[v.getX() + 2][v.getY()] != '$') //down
	{
		res = true;
	}
	else if (v.getY() != 1 && maze.maze[v.getX()][v.getY() - 2] != '*' && maze.maze[v.getX() + 2][v.getY()] != '$') //left
	{
		res = true;
	}
	else if (v.getX() != 1  && maze.maze[v.getX() - 2][v.getY()] != '*' && maze.maze[v.getX() + 2][v.getY()] != '$') //up
	{
		res = true;
	}
	else
		res = false;
	return res;
}

Vertex getRandomNeighbor(Maze maze, Vertex v) 
{
	Vertex neighbor();
	while (neighbor.getData() == '\0') {
		srand((unsigned)time(NULL));
		int i = rand() % 4;
		switch (i) {
			case RIGHT:
			{
				if (v.getY() != (maze.getColumns() - 2) && maze.maze[v.getX()][v.getY() + 2] != '*' && maze.maze[v.getX()][v.getY() + 2] != '$') //right
				{
					neighbor.setX(v.getX());
					neighbor.setX(v.getY() + 2);
					neighbor.setData(' ');
				}
			}
			case DOWN:
			{
				if (v.getX() != (maze.getRows() - 2) && maze.maze[v.getX() + 2][v.getY()] != '*' && maze.maze[v.getX() + 2][v.getY()] != '$') //down
				{
					neighbor.setX(v.getX() + 2);
					neighbor.setX(v.getY());
					neighbor.setData(' ');
				}
			}
			case LEFT:
			{
				if (v.getY() != 1 && maze.maze[v.getX()][v.getY() - 2] != '*' && maze.maze[v.getX() + 2][v.getY()] != '$') //left
				{
					neighbor.setX(v.getX());
					neighbor.setX(v.getY() - 2);
					neighbor.setData(' ');
				}
			}
			case UP:
			{
				if (v.getX() != 1 && maze.maze[v.getX() - 2][v.getY()] != '*' && maze.maze[v.getX() + 2][v.getY()] != '$') //up
				{
					neighbor.setX(v.getX() - 2);
					neighbor.setX(v.getY());
					neighbor.setData(' ');
				}
			}
		}
	}
	return neighbor;
}