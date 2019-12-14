#include "Maze.h"

int main()
{
	int selection, rows, columns;

	srand((unsigned)time(NULL));
	cout << "Maze: 1) From input 2) Random" << endl;
	cin >> selection;

	cin >> rows;
	cin >> columns;
	if (selection == 1) // From input
	{
		Maze maze(rows, columns, nullptr);
		maze.solveMaze();
		maze.show();
	}
	else // Random
	{
		Maze maze(rows, columns); // Create random maze
		maze.solveMaze();
		maze.show();
	}

	// Input options:
	// 1.User's maze(num of rows, num of cols, strings) 2.Random maze(num of rows, num of cols)

	// If user enters his own maze - need to check for valid maze standards

	// NOTE: no need to free user's maze - the d'tor of the class maze will do it.
	// Only if we caught an error in the input validation - we will not create the maze object and
	// free manually char** maze before executing the exit function
}