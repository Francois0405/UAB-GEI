#include <iostream>

using namespace std;

int main()
{
	//DECLARACIONS VARs
	float nota1, nota2, nota3, resultat;
	//ENTRADA
	cout << "Introdueix la primera nota: ";
	cin >> nota1;
	cout << "Introdueix la segona nota: ";
	cin >> nota2;
	cout << "Introdueix la tercera nota: ";
	cin >> nota3;
	//PROCES
	resultat = (nota1 + nota2 + nota3) / 3;
	//SORTIDA

	//FORMAT
	cout << "La mitjana de les tres notes " << nota1 << ", " << nota2 << " i " << nota3 << " es " << resultat << endl;
	cout << endl;
	system("PAUSE");

}