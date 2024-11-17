	#include <iostream>

	using namespace std;

	#define DIM 10

	int main()
	{
		int ind, max;
		int array[DIM];

		for (int i = 0; i < DIM; i++)
		{
			cout << "Introdueix el index " << i << " del vector de " << DIM << " posicions." << endl;
			cin >> array[i];
		}
		max = array[1];
		ind = 1;
		for (int i = 0; i < DIM; i++)
		{
			if (array[i] > max)
			{
				max = array[i];
				ind = i;
			}

		}
		cout << "El maxim del vector es " << max << " i es troba a l'index " << ind << endl;
	}