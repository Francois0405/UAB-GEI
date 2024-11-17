#include <iostream>
#include "vectors.h"
#define n_dies 14
#define n_temp 61

using namespace std;

int main()
{
	int temp[n_dies];
	int histograma[n_temp];
	int ind_max, ind_min, max, min, i;

	LlegirVector(temp, n_dies);
	InicialitzarVector(histograma, 0, n_temp);

	for (i = 0;i < n_dies;i++)
	{
		histograma[temp[i] + 10]++;
		// Quan es -10ºC la posicio del array del histograma es 0
		// Sumem 1 perque hi ha un nou element
	}
	ind_max = MaximVector(histograma, n_temp);
	ind_min = MinimVectorNoZero(histograma, n_temp);

	max = ind_max - 10;
	min = ind_min - 10;

	EscriureVector(histograma, n_temp);
	cout << "Temperatura mes repetida: " << max << " - Temperatura menys repetida : " << min << endl;
}