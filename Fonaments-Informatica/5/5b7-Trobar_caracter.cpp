#include <iostream>
#include "funcions.h";
using namespace std;

int main()
{
	char string[30], caracter;

	cout << "Introdueix una paraula" << endl;
	cin >> string;
	cout << "Introdueix el caracter a buscar: ";
	cin >> caracter;

	cout << "Cadena: " << string << endl;
	cout << "Caracter: " << caracter << endl;
	if (TrobarCaracter(string,caracter) == 1)
	{
		cout << "Trobat!" << endl;
	}
	else {
		cout << "No trobat :(" << endl;
	}
}