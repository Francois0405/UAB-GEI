#include <iostream>

using namespace std;

void OrdenarVector(int array[], int DIM)
{
	//Ordenar de mas pequeño a mas grande
	int i = 0, guardar;
	int max, ind_max=0;

	for (int y = 0;y < DIM;y++)
	{	
		max = array[0];
		ind_max=0;
		for (i = 0; i < DIM-y; i++) // Saca el maximo
		{
			if (max < array[i])
			{
				max = array[i];
				ind_max = i;
			}
		}
		guardar = array[DIM - y-1];
		array[DIM - y-1] = max;
		array[ind_max] = guardar;
	}
}


int main()
{
	int array[8];
	for (int i = 0;i < 4;i++)
	{
		cout << "Introdueix el numero " << i << ": ";
		cin >> array[i];
	}
	OrdenarVector(array, 4);

	cout << "Array ordenat: ";
	
	for (int i = 0;i < 4;i++)
	{
		cout << array[i] << " ";
	}
}