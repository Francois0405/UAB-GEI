#include <iostream>

using namespace std;

int main()
{
	int opcio;
	char sortir = 'S';
	float a, b, res;
	
	cout << "Introdueix dos numeros" << endl;
	cin >> a >> b;
	do {
		cout << "/ x - + [CALCULADORA] + - x / " << endl
			<< "Selecciona una de les opcions" << endl <<
			"1.- Suma" << endl << "2.- Resta" << endl <<
			"3.- Producte" << endl << "4.- Divisio" << endl 
			<< "5.- Sortir" << endl << endl;
		cin >> opcio;


		switch (opcio)
		{
		case 1:
		{
			res = a + b;
			cout << a << " + " << b << " = " << res << endl;
		}
			break;
		case 2:
		{
			res = a - b;
			cout << a << " - " << b << " = " << res << endl;
		}
			break;
		case 3:
		{
			res = a * b;
			cout << a << " x " << b << " = " << res << endl;
		}
			break;
		case 4:
		{
			if (b != 0)
			{
				res = a / b;
				cout << a << " : " << b << " = " << res << endl;
			}
			else
			{
				cout << "Error: Divisio per zero" << endl;
			}
		}
			break;
		case 5:
		{
			cout << "Vols operar amb uns altres operands ? (S / -)";
			cin >> sortir;

			if (sortir == 'S')
			{
				cout << "Introdueix dos numeros" << endl;
				cin >> a >> b;
			}
			else
			{
				cout << "Sortint... " << endl;
			}
			}
			break;
		default: cout << "Error: Opcio no valida" << endl;
			break;
		}
	} while (sortir == 'S');
}