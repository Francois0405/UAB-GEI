#include <iostream>

using namespace std;

int main()
{
	//VAR
	float x, calA, calB;
	//ENTRADA
	cout << "Introdueix la variable x: ";
	cin >> x;
	//PROCES
	calA = 2 / (x - 4);
	calB = (1 + 4 - x) / (3 * (x + 3));
	//SORTIDA
	cout << "Resultat: " << calA <<endl;
	cout << "Resultat: " << calB <<endl;
}