	#include <iostream>

	using namespace std;

	#define DIM 12

	int main()
	{
		int array[DIM];

		for (int i = 0;i < DIM; i++)
		{
			cout << "Introdueixi la posicio " << i << " de l'array: ";
			cin >> array[i];
		}
		cout << "Entrada: ";
		for (int i = 0; i < DIM; i++)
		{
			cout << array[i] << " ";
		}
		for (int i = 0; i < DIM; i++)
		{
			if (array[i] < 0)
			{
				array[i] = 0;
			}
		}
		cout << endl << "Sortida: ";
		for (int i = 0; i < DIM; i++)
		{
			cout << array[i] << " ";
		}
	}