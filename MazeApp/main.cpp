#include "Maze.h"

int main()
{
	Stack s;
	Vertex v;
	char c;

	cout << "Enter vertex data: ";
	cin >> c;

	while (c != '$') 
	{
		v = Vertex((int)c, (int)c, c);
		s.push(v);
		v.show();
		cout << endl;

		cout << "\nEnter vertex data: ";
		cin >> c;
	}

	while (!s.isEmpty()) 
	{
		s.pop().show();
		cout << endl;
	}

	// TODO: if user enters his own maze - need to check for valid maze standards

	// NOTE: no need to free user's maze - the d'tor of the class maze will do it.
	// Only if we caught an error in the input validation - we will not create the maze object and
	// free it manually before executing the exit function
}