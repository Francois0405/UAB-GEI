#include <iostream>

using namespace std;

int main()
{
	//VAR
	int nombre, milers;
	//ENTRADA
	cout << "Introdueix el teu nombre ";
	cin >> nombre;
	//PROCES
	milers = (nombre / 1000) % 10;
	//SORTIDA
	cout << "Les unitats de miler del nombre "<< nombre << " son " << milers;
}