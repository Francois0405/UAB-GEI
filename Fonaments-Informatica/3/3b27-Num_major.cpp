#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d; // Els quatre nombres
	int x; // nombre de comparacions

	x = 0;

	cout << "Introdueixi quatre nombres: ";
	cin >> a >> b >> c >> d;

	if (a > b)
	{
		// b no es el mayor
		x = x + 1;
		if (a > c)
		{
			// c no es el mayor
			x = x + 1;
			if (a > d)
			{
				// d no es el mayor -> "a"
				x = x + 1;
				cout << "El numero mes gran de la serie es " << a << ". Comparacions: " << x;
			}
			else
			{
				// mayor -> "d"
				x = x + 1;
				cout << "El numero mes gran de la serie es " << d << ". Comparacions: " << x;
			}
		}
		else // a no es el mayor
		{
			x = x + 1;
			if (c > d)
			{
				// mayor -> "c"
				x = x + 1;
				cout << "El numero mes gran de la serie es " << c << ". Comparacions: " << x;
			}
			else
			{
				// mayor -> "d"
				x = x + 1;
				cout << "El numero mes gran de la serie es " << d << ". Comparacions: " << x;
			}
		}
	}
	else // a no es el 
	{
		x = x + 1;
		if (b > c)
		{
			// c no es el mayor
			x = x + 1;
			if (b > d)
			{
				// mayor -> "b"
				x = x + 1;
				cout << "El numero mes gran de la serie es " << b << ". Comparacions: " << x;
			}
			else
			{
				// mayor -> "d"
				x = x + 1;
				cout << "El numero mes gran de la serie es " << d << ". Comparacions: " << x;
			}
		}
		else // b no es el mayor
		{
			x = x + 1;
			if (c > d)
			{
				// mayor -> "c"
				x = x + 1;
				cout << "El numero mes gran de la serie es " << c << ". Comparacions: " << x;
			}
			else
			{
				//mayor -> "d"
				x = x + 1;

				cout << "El numero mes gran de la serie es " << d << ". Comparacions: " << x;
			}
		}
	}
}