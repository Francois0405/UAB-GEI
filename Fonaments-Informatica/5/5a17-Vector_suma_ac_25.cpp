#include <iostream>

#define DIM 10

using namespace std;

int main()
{
	float array[DIM], sum=0;
	bool mes25=false;
	int i;

	for (i = 0; i < DIM; i++)
	{
		cout << "Introdueix la posicio " << i << " de l'array: ";
		cin >> array[i];
	}
	i = 0;
	while ((!mes25) && (i < DIM))
	{
		if (sum < 25)
		{
			sum = sum + array[i];
		}
		if (sum > 25)
		{
			mes25 = true;
			cout << "A la posicio " << i + 1 << " la suma acumulada es superior a 25";
		}
		
		i++;
	}
	if (mes25 == false) 
	{
		cout << "La suma acumulada de l'array es inferior o igual a 25";
	}
}