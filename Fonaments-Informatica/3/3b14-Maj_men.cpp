#include <iostream>

using namespace std;

int main()
{
	int edat;
	int anyN;
	int const anyA = 2024;
	cout << "Introdueix el teu any de naixement: ";
	cin >> anyN;
	edat = anyA - anyN;
	cout << "Tens " << edat << " anys i ets ";
	if (edat < 18)
	{
		cout << "menor d'edat.";
	}
	else
	{
		cout << "major d'edat.";
	}
}