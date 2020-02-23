#include "Maze.h"

int main()
{
	int selection, rows, columns;

	cout << "Welcome to the maze app!\n" << endl;
	cout << "Press 1 to enter your own maze.\n";
	cout << "Press 2 to create a random maze.\n";
	cout << "Your selection: ";
	cin >> selection;
	cout << endl << "Please enter the number of rows: ";
	cin >> rows;
	cout << "Please enter the number of columns: ";
	cin >> columns;

	// Invalid selection or invalid number of rows or columns
	if ((selection != FROM_INPUT && selection != RANDOM) || !(1 <= rows && rows <= MAX_ROWS) || !(1 <= columns && columns <= MAX_COLUMNS))
	{
		cout << endl << "Invalid input!" << endl;
		exit(INVALID_INPUT_ERROR);
	}
	
	srand((unsigned)time(NULL));
	Maze maze(rows, columns);

	if (selection == FROM_INPUT) // Set maze from input
	{
		maze.setUserMaze();
	}
	else if (selection == RANDOM) // Set random maze
	{
		maze.setRandomMaze();
	}

	maze.solve(); // Solve the resulting maze
	maze.show(); // Print solved maze
}