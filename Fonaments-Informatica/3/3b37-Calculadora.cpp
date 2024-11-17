#include <iostream>

using namespace std;

int main()
{
	int opcio;
	float a, b, res;
	char signe;

	cout << "MENU";
	cout << "1.- Suma" << endl;
	cout << "2.- Resta" << endl;
	cout << "3.- Producte" << endl;
	cout << "4.- Divisio" << endl;
	cout << "5.- Sortir" << endl;
	cout << "Selecciona una de les opcions:" << endl;

	cin >> opcio;
	
	cout << "Selecciona dos nombres per fer l'acció: ";
	cin >> a >> b;

	switch (opcio)
	{
	case 1:
	{
		res = a + b;
		signe = '+';
		cout << a << " " << signe << " " << b << " = " << res << endl;
	}
		break;
	case 2:
	{
		res = a - b;
		signe = '-';
		cout << a << " " << signe << " " << b << " = " << res << endl;
	}
		break;
	case 3:
	{
		res = a * b;
		signe = 'x';
		cout << a << " " << signe << " " << b << " = " << res << endl;
	}
		break;
	case 4:
	{
		signe = '/';
		if (b != 0)
		{
			res = a / b;
			cout << a << " " << signe << " " << b << " = " << res << endl;
		}
		else
			cout << "Error: Divisio per zero";
	}
		break;
	case 5: cout << "Sortint de la calculadora...";
		break;
	default: cout << "Error: Opcio no valida";
		break;
	}

}