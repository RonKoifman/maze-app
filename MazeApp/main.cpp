#include "Maze.h"

int main()
{
	srand((unsigned)time(NULL));

	// CHECKING RANDOM MAZE
	Maze maze(25, 25);
	maze.show();
	maze.solveMaze();
	cout << endl << "=============================================================\n" << endl;
	maze.show();
	cout << endl;

	// Input options:
	// 1.User's maze(num of rows, num of cols, strings) 2.Random maze(num of rows, num of cols)

	// If user enters his own maze - need to check for valid maze standards

	// NOTE: no need to free user's maze - the d'tor of the class maze will do it.
	// Only if we caught an error in the input validation - we will not create the maze object and
	// free manually char** maze before executing the exit function
}