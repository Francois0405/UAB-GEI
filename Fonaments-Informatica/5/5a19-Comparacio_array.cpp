#include <iostream>

#define DIM 6

using namespace std;

int main()
{
	int array1[DIM], array2[DIM], i;
	bool diferents = false;

	for (i = 0;i < DIM;i++)
	{
		cout << "Introdueix l'index " << i << " de la primera array: ";
		cin >> array1[i];
	}
	for (i = 0;i < DIM;i++)
	{
		cout << "Introdueix l'index " << i << " de la segona array: ";
		cin >> array2[i];
	}
	i = 0;
	while ((!diferents) && (i < DIM))
	{
		if (array1[i] != array2[i])
		{
			diferents = true;
			cout << "DIFERENTS";
		}
		i++;
	}
	if (diferents == false)
	{
		cout << "IGUALS";
	}
	

}