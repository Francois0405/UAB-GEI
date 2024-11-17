#include <iostream>

using namespace std;

int main()
{
	float const iva = 0.07;
	float desc;
	float preu;
	float preu_tot;
	float num;
	
	cout << "Introdueix el preu sense IVA i la quantitat venuda: ";
	cin >> preu >> num;

	preu_tot = preu * num;
	preu_tot = preu_tot + preu_tot * iva;

	if (preu_tot <= 500)
	{
		desc = 0;
	}
	else
	{
		if (preu_tot <= 1000)
		{
			desc = 0.05;
		}
		else
		{
			if (preu_tot > 1000)
			{
				desc = 0.1;
			}
		}
	}
	preu_tot = preu_tot - preu_tot * desc;
	cout << "L'import final de la compra son " << preu_tot << " euros.";
}