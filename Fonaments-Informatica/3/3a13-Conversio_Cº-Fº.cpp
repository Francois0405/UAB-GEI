#include <iostream>

using namespace std;

int main()
{
	//VAR
	float C, F;
	//ENTRADA
	cout << "Introdueix la temperatura en graus C: ";
	cin >> C;
	//PROCES
	F = (float(9) / 5) * C + 32;
	//SORTIDA
	cout << C << " graus Celsius son " << F << " graus Fahrenheit." << endl;

}