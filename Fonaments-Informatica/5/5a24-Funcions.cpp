#include <iostream>

using namespace std;

void InicialitzarVector(int vector[], int n, int DIM)
{
	for (int i = 0; i < DIM; i++)
	{
		vector[i] = n;
	}
}

void EscriureVector(int vector[], int DIM)
{
	for (int i = 0; i < DIM; i++)
	{
		cout << vector[i] << " ";
	}
	cout << endl;
}

void LlegirVector(int vector[], int DIM)
{
	cout << "Introdueix cada nombre del vector un per un." << endl;
	for (int i = 0; i < DIM; i++)
	{
		cin >> vector[i];
	}
}

float MitjanaVector(int vector[], int DIM)
{
	float sum = 0, mitjana; // La quantitat de dades = DIM

	for (int i = 0;i < DIM;i++)
	{
		sum = sum + vector[i];
	}
	mitjana = sum / DIM;
	return mitjana;
}

int MaximVector(int vector[], int DIM)
{
	int max, ind_max;

	max = vector[0];
	ind_max = 0;
	for (int i = 0; i < DIM; i++)
	{
		if (max < vector[i])
		{
			ind_max = i;
			max = vector[i];
		}
	}
	return ind_max;
}

int MinimVector(int vector[], int DIM)
{
	int min, ind_min;

	min = vector[0];
	ind_min = 0;
	for (int i = 0; i < DIM; i++)
	{
		if (min > vector[i])
		{
			min = vector[i];
			ind_min = i;
		}
	}
	return ind_min;
}

int MinimVectorNoZero(int vector[], int DIM)
{
	int min, ind_min = -1; // Set ind_min to -1 initially
	bool tenim_min = false;
	int i = 0;

	while (i < DIM && !tenim_min)
	{
		if (vector[i] != 0)
		{
			tenim_min = true;
			min = vector[i];
			ind_min = i;
		}
		i++;
	}
	if (!tenim_min)
	{
		return -1;
	}
	for (i = 0; i < DIM; i++)
	{
		if (vector[i] != 0 && vector[i] < min)
		{
			min = vector[i];
			ind_min = i;
		}
	}

	return ind_min;
}
