#include <iostream>
#include <math.h>

using namespace std;

float divisio(int a, int b, int &div, int &residu)
{
	//div = a / b;
	bool negatiu = false;
	if (b != 0)
	{
		if ((a < 0 && b > 0) || (a > 0 && b < 0))
		{
			negatiu = true;
		}
		residu = a % b; // Calculem el residu de la divisio, el que resta.

		a = abs(a);
		b = abs(b);

		while (a >= b) {
			a = a - b; //a-=b;
			div++;
		}
		if (negatiu) {
			div = -div;
		}

		return 0;
	}
	else
	{
		return 1;
	}	
}

int main()
{
	int dividend, divisor;

	cout << "Introdueix un dividend i un divisor: " << endl;
	cin >> dividend >> divisor;
	int div = 0;
	int residu = 0;
	
	if (divisio(dividend, divisor, div, residu) == 0)
	{
		cout << "Ha introduit: " << dividend << " : " << divisor << endl;
		cout << "Resultat - Quocient: " << div << " i Residu: " << residu << endl;
	}
	else
	{
		cout << "Error: Divisio per zero" << endl;
	}
}