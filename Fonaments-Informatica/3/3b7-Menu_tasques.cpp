#include <iostream>

using namespace std;

int main()
{
	int v;
	cout << "Escull una opció: ";
	cin >> v;

	switch (v)
	{
	case 1: cout << "Fent tasca " << v;
		break;
	case 2: cout << "Fent tasca " << v;
		break;
	case 3: cout << "Fent tasca " << v;
		break;
	default: cout << "Opcio incorrecta";
		break;
	}
}