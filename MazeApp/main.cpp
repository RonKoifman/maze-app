#include "Maze.h"

int main()
{
	int selection, rows, columns;

	srand((unsigned)time(NULL));
	cout << "Maze: 1) From input 2) Random" << endl;
	cin >> selection;
	cin >> rows;
	cin >> columns;

	if (!(1 <= rows && rows <= MAX_ROWS) || !(1 <= columns && columns <= MAX_COLUMNS)) // Invalid number of rows or columns
	{
		cout << "invalid input" << endl;
		exit(INVALID_INPUT_ERROR);
	}
	else
	{
		if (selection == FROM_INPUT) // From input
		{
			Maze maze(rows, columns, nullptr); // Set user's maze and solve it
			maze.solveMaze();
			maze.show();
		}
		else if (selection == RANDOM) // Random
		{
			Maze maze(rows, columns); // Create random maze and solve it
			maze.solveMaze();
			maze.show();
		}
		else // Invalid option choice
		{
			cout << "invalid input" << endl;
			exit(INVALID_INPUT_ERROR);
		}
	}
}