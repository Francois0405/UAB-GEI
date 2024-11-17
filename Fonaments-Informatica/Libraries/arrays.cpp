#include <iostream>
using namespace std;

void SumaVectors(int vector[DIM], int vector2[DIM], int vector3[DIM])
{
	for (int i = 0; i < DIM; i++)
	{
		vector3[i] = vector2[i] + vector[i];
	}
}

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
	for (int i = 0; i < DIM; i++)
	{
		if (max <= vector[i])
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
	for (int i = 0; i < DIM; i++)
	{
		if (min >= vector[i])
		{
			min = vector[i];
			ind_min = i;
		}
	}
	return ind_min;
}

int MinimVectorNoZero(int vector[], int DIM)
{
	int min, ind_min;
	bool nototzero = false;
	int i = 0;
	while ((!nototzero) && (i < DIM))
	{
		if (vector[i] != 0)
		{
			min = vector[i];
			ind_min = i;
			nototzero = true;
		}
		i++;
	}
	if (nototzero == false)
	{
		ind_min = -1;
	}
	else
	{
		for (i = 0; i < DIM; i++)
		{
			if ((min >= vector[i]) && (vector[i] != 0))
			{
				min = vector[i];
				ind_min = i;
			}
		}
	}
	return ind_min;
}

bool OrdenatDecreixent(int vector[], int DIM)
{
	bool acabat = false;
	int i = 0, guardar;

	while ((i < DIM - 1) && (!acabat))
	{
		if (vector[i + 1] > vector[i])
		{
			acabat = true;
		}
		else
		{
			i++;
		}
	}
	if (acabat == true)
	{
		return 0;
	}
	else {
		return 1;
	}
}

int BuscarPosicio(int vector[], int num, int DIM)
{
	bool acabat = false;
	int i = 0, retorn;

	while ((!acabat) && (i < DIM))
	{
		if (num > vector[i])
		{
			retorn = i;
			acabat = true;
		}
		i++;
	}
	if (acabat == false)
	{
		return -1;
	}
	else {
		return retorn;
	}
}

bool InversArray(int vector[], int vector1[], int DIM)
{
	bool incorrecte = false;
	int i = 0;
	while ((incorrecte == false) && (i < DIM))
	{
		if (vector[i] != vector1[DIM - i - 1])
		{
			incorrecte = true;
		}
		i++;
	}
	if (incorrecte == false)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void OrdenarVector(int array[], int DIM)
{
	//Ordenar de mas pequeño a mas grande
	int i = 0, guardar;
	int max, ind_max = 0;

	for (int y = 0;y < DIM;y++)
	{
		max = array[0];
		ind_max = 0;
		for (i = 0; i < DIM - y; i++) // Saca el maximo
		{
			if (max < array[i])
			{
				max = array[i];
				ind_max = i;
			}
		}
		guardar = array[DIM - y - 1];
		array[DIM - y - 1] = max;
		array[ind_max] = guardar;
	}
}
