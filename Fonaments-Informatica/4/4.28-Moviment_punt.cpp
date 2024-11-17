#include <iostream>
#include "funcio.h"

using namespace std;

int main()
{
	int x, y;
	int x_min, x_max, y_min, y_max;
	int direccio;

	cout << "Introdueixi els limits del mapa: (xmin, xmax, ymin, ymax)" << endl;
	cin >> x_min >> x_max >> y_min >> y_max;

	while ((x_min >= x_max) || (y_min >= y_max))
	{
		cout << "Error: Limits incorrectes, torni a introduir limits: " << endl;
		cout << "(xmin, xmax, ymin, ymax)" << endl;
		cin >> x_min >> x_max >> y_min >> y_max;
	}
	//a
	cout << "Molt be, ara introdueixi les coordenades on esteu situats en el mapa (x,y): " << endl;
	cin >> x >> y;

	while (x < x_min || x > x_max || y < y_min || y > y_max)
	{
		cout << "Error: Coordenades fores del limit, torni a introduir coordenades: " << endl;
		cout << "(x,y)" << endl;
		cin >> x >> y;
	}

	cout << "Ara pot controlar el seu personatge en el mapa." << endl;
	do {
		//menu();
		cin >> direccio;

		if (direccio >= 1 && direccio < 5)
		{
			moviment(x, y, x_min, x_max, y_min, y_max, direccio);
			cout << "(" << x << ", " << y << ")" << endl;

		}
		else
		{
			if (direccio != 5)
			{
				cout << "Error: Direccio no valida, torni a introduir: " << endl;
				cin >> direccio;
			}
		}
	} while (direccio != 5);

	return 0;
}