#include <iostream>

using namespace std;

int main()
{
	float num, max, min, quant;

	cout << "Introdueix una sequencia de numeros per calcular el maxim i el minim, introdueix un numero negatiu per acabar la sequencia." << endl;
	cin >> num;
	quant = 1;
	if (num < 0)
	{
		cout << "No hi ha nombres a la sequencia" << endl;
	}
	else
	{
		max = num;
		min = num;
		while (quant <= 10 && num >= 0)
		{
			cin >> num;
			quant = quant + 1;
			if (num >= 0)
			{
				if (num > max)
				{
					max = num;
				}
				if (num < min)
				{
					min = num;
				}
			}
		}
		cout << "Maxim: " << max << " - Minim: " << min << endl;
	}
}