#include <iostream>

using namespace std;

int main()
{
	float EUR, USD, GBP, CHF, JPY;
	int v;

	cout << "Introdueix una quantitat de euros a canviar: ";
	cin >> EUR;

	cout << "Selecciona una divisa a la quals vols canviar pels teus euros. " << endl;
	cout << "1-Dolars(USD)" << endl << "2-Lliures(GBP)" << endl << "3-Francs suïssos(CHF)" << endl << "4-Yens(JPY)" << endl;
	cin >> v;

	switch (v)
	{
	case 1:
	{
		USD = 1.34 * EUR;
		cout << EUR << " euros son " << USD << " USD";
	}
		break;
	case 2:
	{
		GBP = 0.83 * EUR;
		cout << EUR << " euros son " << GBP << " GBP";
	}
	break;
	case 3:
	{
		CHF = 1.23 * EUR;
		cout << EUR << " euros son " << CHF << " CHF";
	}
		break;
	case 4:
	{
		JPY = 133.11 * EUR;
		cout << EUR << " euros son " << JPY << " JPY";
	}
		break;
	default: cout << "Error: moneda no disponible";
		break;
	}
}