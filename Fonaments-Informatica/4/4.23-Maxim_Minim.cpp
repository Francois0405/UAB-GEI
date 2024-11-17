#include <iostream>

using namespace std;

int maxmin(float num, float &min, float &max)
{
	float quant;
	quant = 1;
	if (num == 0)
	{
		return 1;
	}
	else
	{
		max = num;
		min = num;
		while (quant <= 10 && num != 0)
		{
			cin >> num;
			quant = quant + 1;
			if (num != 0)
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
		return 0;
	}
}

int main()
{
	float num, min=0, max=0;

	cout << "Introdueix una sequencia de numeros per calcular el maxim i el minim, introdueix un numero negatiu per acabar la sequencia." << endl;
	cin >> num;

	int res = maxmin(num, min, max);

	if (res == 0) 
	{
		cout << "El minim de la sequencia es " << min << " i el maxim es " << max << endl;
	}
	else
	{
		cout << "Error: sequencia buida";
	}
}
