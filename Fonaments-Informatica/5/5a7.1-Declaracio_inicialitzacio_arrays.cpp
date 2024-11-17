#include <iostream>

using namespace std;
#define DIM 10 //dimensio

int main()
{
	int v1[DIM] = { 0,1,2,3,4,5,6,7,8,9 };
	int v2[DIM], v3[DIM], v4[DIM];
	int i;

	for (i = 0;i < DIM; i++)
	{
		v2[1] = 2 * i;

		cout << "Introduir valor posicio array " << i << ": ";
		cin >> v3[i];

		v4[i] = v1[i] + v2[i] + v3[i];
	}

	cout << "Vector 1: ";
	for (i = 0;i < DIM; i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	cout << "Vector 2: ";
	for (i = 0;i < DIM; i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;
	cout << "Vector 3: ";
	for (i = 0;i < DIM; i++)
	{
		cout << v3[i] << " ";
	}
	cout << endl;
	cout << "Vector 4: ";
	for (i = 0;i < DIM; i++)
	{
		cout << v4[i] << " ";
	}
	cout << endl;
}