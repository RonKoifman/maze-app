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