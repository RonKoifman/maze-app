/* Instructions:
This program accepts a given maze or creates a random maze and solves it.
The program will receive as an input one of the two options:
(1) for creating a maze from user's input (2) for creating a random maze.
Additionally, the program will receive the requested number of rows and columns.
If the chosen option is (1) - the user will also insert to the program his given maze.
For a solvable maze - the solved maze will be printed, otherwise an appropriate
error message will be printed. */

#include "Maze.h"

int main()
{
	int selection, rows, columns;

	srand((unsigned)time(NULL));

	cout << "Maze: 1) From input 2) Random" << endl;
	cin >> selection >> rows >> columns;

	// Invalid selection or invalid number of rows or columns
	if ((selection != FROM_INPUT && selection != RANDOM) || !(1 <= rows && rows <= MAX_ROWS) || !(1 <= columns && columns <= MAX_COLUMNS))
	{
		cout << "invalid input" << endl;
		exit(INVALID_INPUT_ERROR);
	}
	
	Maze maze(rows, columns);

	if (selection == FROM_INPUT) // From input
	{
		maze.setUserMaze();
	}
	else if (selection == RANDOM) // Random
	{
		maze.setRandomMaze();
	}

	maze.solve(); // Solve the resulting maze
	maze.show(); // Print solved maze
}