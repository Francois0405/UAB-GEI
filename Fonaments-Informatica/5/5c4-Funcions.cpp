#include <iostream>

using namespace std;
#define N_COL 3

void LlegirMatriu(float M[][N_COL], int n_fil, int n_col)
{
	for (int i = 0; i < n_fil;i++)
	{
		for (int j = 0;j < n_col;j++)
		{
			cout << "Introdueix M" << "[" << i << "]" << "[" << j << "]: ";
			cin >> M[i][j];
		}
	}
}

void EscriureMatriu(float M[][N_COL], int N_FIL, int n_col)
{
	for (int i = 0; i < N_FIL;i++)
	{
		for (int j = 0;j < n_col;j++)
		{
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
}