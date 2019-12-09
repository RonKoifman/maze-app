#include "Maze.h"
#include <ctime>

int main()
{
	srand((unsigned)time(NULL));
	std::time_t result = std::time(nullptr);
	std::cout << std::asctime(std::localtime(&result));

	Maze maze(11, 11);
	maze.show();

	result = std::time(nullptr);
	std::cout << std::asctime(std::localtime(&result));

	// TODO: if user enters his own maze - need to check for valid maze standards

	// NOTE: no need to free user's maze - the d'tor of the class maze will do it.
	// Only if we caught an error in the input validation - we will not create the maze object and
	// free it manually before executing the exit function
}
