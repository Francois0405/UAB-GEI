#include <iostream>

using namespace std;

void moviment(int& x, int& y, int xmin, int xmax, int ymin, int ymax, int direccio)
{
	switch (direccio)
	{
	case 1: //esquerra
		if (x > xmin)
			x--;
		else
			cout << "No es pot moure a l'esquerra, esta en el limit." << endl;
		break;
	case 2: //dreta
		if (x < xmax)
			x++;
		else
			cout << "No es pot moure a la dreta, esta en el limit." << endl;
		break;
	case 3: //dalt
		if (y < ymax)
			y++;
		else
			cout << "No es pot moure a dalt, esta en el limit." << endl;
		break;
	case 4: //Baix
		if (y > ymin)
			y--;
		else
			cout << "No es pot moure a baix, esta en el limit." << endl;
		break;
	}
}

void menu(void)
{
	cout << "1: Esquerra" << endl;
	cout << "2: Dreta" << endl;
	cout << "3: Dalt" << endl;
	cout << "4: Baix" << endl;
	cout << "5: Sortir" << endl;
}