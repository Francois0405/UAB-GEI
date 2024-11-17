#include <iostream>
#include "equacio.h"

using namespace std;

int main()
{
	int a, b, c;
	float x1, x2;

	cout << "Introdueix a, b, c d'una equacio quadratica: " << endl;
	cin >> a >> b >> c;

	if (equacio(a, b, c, x1, x2) == 0)
	{

	}
	else
	{
		if (equacio(a, b, c, x1, x2) == 1)
		{
			cout << "El sistema té una arrel doble -> x1 = x2." << endl;
			cout << "La arrel és: " << x1;
		}
		else
		{
			cout << "El sistema té dues arrels. " << endl;
			cout << "x1 = " << x1 << " - x2 = " << x2 << endl;
		}
	}
}