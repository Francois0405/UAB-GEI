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