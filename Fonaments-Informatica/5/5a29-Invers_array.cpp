#include <iostream>
#include "funcions.h"

using namespace std;

#define DIM 6

int main()
{
	int array[DIM], array1[DIM];
	bool invers;
	cout << "Introdueix array1: " << endl;
	for (int i = 0;i < DIM; i++)
	{
		cin >> array[i];
	}
	cout << "Introdueix array2: " << endl;
	for (int i = 0;i < DIM; i++)
	{
		cin >> array1[i];
	}
	invers = InversArray(array, array1, DIM);
	if (invers == 1)
	{
		cout << "Les dos arrays son invertibles" << endl;
	}
	else
	{
		cout << "Les dos arrays no son invertibles" << endl;
	}

}