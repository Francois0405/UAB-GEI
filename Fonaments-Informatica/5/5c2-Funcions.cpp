#include <iostream>
#include "matrius.h"

using namespace std;

#define N_FIL 2
#define N_COL 3

void LlegirMat(int mat[N_FIL][N_COL], int n_fil,int n_col)
{
	int f, c;
	for (f = 0;f < n_fil;f++)
	{
		for (c = 0;c < n_col;c++)
		{
			cout << "Introdueix mat[" << f << "][" << c << "]: ";
			cin >> mat[f][c];
		}
	}
}

void EscriureMat(int mat[N_FIL][N_COL], int n_fil, int n_col)
{
	int f, c;
	for (f = 0;f < n_fil;f++)
	{
		for (c = 0;c < n_col;c++)
		{
			cout << mat[f][c];
		}
		cout << endl;
	}
}

void SumarMat(int mat1[N_FIL][N_COL], int mat2[N_FIL][N_COL], int matres[N_FIL][N_COL], int n_fil, int n_col)
{
	int f, c;
	for (f = 0;f < n_fil;f++)
	{
		for (c = 0;c < n_col;c++)
		{
			matres[f][c] = mat1[f][c] + mat2[f][c];
		}
	}
}