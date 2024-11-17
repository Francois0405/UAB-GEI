#include <iostream>

using namespace std;

int main()
{
	int any;
	int dies;
	cout << "Digues un any: ";
	cin >> any;
	if (((any % 4 == 0) && (any % 100 != 0)) || (any % 400 == 0))
	{
		dies = 29;
	}
	else
	{
		dies = 28;
	}
	cout << "A l'any " << any << " febrer te " << dies << " dies.";
}
