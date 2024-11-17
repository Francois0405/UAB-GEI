#include <iostream>

using namespace std;

int main()
{
	//VAR
	int anynaix, anyactual, edat;
	//ENTRADA
	cout << "Introdueix el teu any de naixement: ";
	cin >> anynaix;
	//PROCES
	anyactual = 2024;
	edat = anyactual - anynaix;
	//SORTIDA
	cout << "Tens " << edat << " anys" << endl;
}