#include <iostream>

using namespace std;

int main()
{
	// Inicialització
	int A[3][4] = {
		{6,7,8,9},
		{6,5,4,3},
		{1,0,0,1}
	};
	int B[5][3];

	for (int i = 0;i < 5;i++) //files
	{
		for (int j = 0;j < 3;j++)
		{
			B[i][j] = 5 * i + j;
		}
	}
	
	// Escritura
	// MAT A
	cout << "Matriu A" << endl;
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	// MAT B
	cout << "Matriu B" << endl;
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
}