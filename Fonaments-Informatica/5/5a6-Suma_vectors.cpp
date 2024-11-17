#include <iostream>

#define DIM 5

using namespace std;

void LlegirVector(int vector[DIM])
{
	cout << "Introdueix cada nombre del vector un per un." << endl;
	for (int i = 0; i < DIM; i++)
	{
		cin >> vector[i];
	}
}

void EscriuVector(int vector[DIM])
{
	cout << "Ara introduire el vector." << endl;
	for (int i = 0; i < DIM; i++)
	{
		cout << vector[i] << " ";
	}
}

void SumaVectors(int vector[DIM], int vector2[DIM], int vector3[DIM])
{
	for (int i = 0; i < DIM; i++)
	{
		vector3[i] = vector2[i] + vector[i];
	}
}

int main()
{
	int vector[DIM], vector2[DIM], vector3[DIM];
	LlegirVector(vector);
	//EscriuVector(vector);

	LlegirVector(vector2);
	//EscriuVector(vector2);

	SumaVectors(vector, vector2, vector3);
	EscriuVector(vector3);
}