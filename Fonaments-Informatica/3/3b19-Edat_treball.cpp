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
	cout << "Tens " << edat << " anys " << endl;

	if (edat >= 18)
	{
		cout << "i ets major d'edat." << endl;
		if (edat < 67)
			cout << "Estas en edat de treballar.";
		else
			cout << "Estas en edat de jubilacio.";
	}
	else
	{
		cout << "i ets menor d'edat." << endl;
		if (edat > 12)
			cout << "Has acabat primaria.";
		else
			cout << "Encara no has acabat primaria.";
	}
}