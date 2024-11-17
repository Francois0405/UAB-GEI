#include <iostream>
#include "DivisioEnters.h"

using namespace std;

int main()
{
	int dividend, divisor, res=0;

	cout << "Introdueix un dividend y un divisor: " << endl;
	cin >> dividend >> divisor;

	DivisioEnters(dividend, divisor, res);

	if (DivisioEnters(dividend, divisor, res) == 1)
	{
		cout << "Resultat de la divisio: " << res << endl;
	}
	else
	{
		cout << "Error: Divisio per zero" << endl;
	}
}