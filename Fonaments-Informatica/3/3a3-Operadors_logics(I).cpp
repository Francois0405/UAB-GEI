#include <iostream>

using namespace std;

int main()
{
	//VAR
	float a;
	bool res;
	//ENT
	cout << "Introdueix un nombre: ";
	cin >> a;
	//PRO
	res = (a > 0) && (a < 10);
	//SOR
	cout << "El resultat de la comparacio es: " << res;
}