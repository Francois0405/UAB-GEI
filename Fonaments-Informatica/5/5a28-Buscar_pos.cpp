#include <iostream>
#include "funcions.h"
#define DIM 5

using namespace std;

int main()
{
	int array[DIM], num, retorn;
	cout << "Atenció Introdueixi el vector en ordre decreixent!" << endl;
	LlegirVector(array, DIM);
	if (OrdenatDecreixent(array, DIM) == 1)
	{
		cout << "Molt be ara introdueix un valor a afegir: ";
		cin >> num;

		retorn = BuscarPosicio(array, num, DIM);
		if (retorn == -1)
		{
			cout << "Tots els valors del vector son mes grans que " << num << endl;
		}
		else
		{
			cout << "El valor ha d'anar a la posicio " << retorn;
		}

	}
	else {
		cout << "El vector no esta correctament ordenat" << endl;
	}
}