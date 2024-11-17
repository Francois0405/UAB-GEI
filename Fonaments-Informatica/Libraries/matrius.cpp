#include <iostream>
#include "matrius.h"

using namespace std;

void ProducteMatrius(float mat1[N_FIL1][N_COL1], float mat2[N_FIL2][N_COL2], float mat3[N_FIL1][N_COL2], int n_fil, int n_col)
{
	int i, j, k;
	for (i = 0;i < n_fil;i++) // Recorrem les files mat1
	{
		for (j = 0;j < n_col;j++) // Recorrem les Columnes de mat2
		{
			mat3[i][j] = 0;
			for (k = 0;k < N_COL1;k++) // Recorrem les col de mat1 i fil de mat2 (mateix numero)
			{
				mat3[i][j] = (mat1[i][k] * mat2[k][j]) + mat3[i][j];
			}
		}
	}
}

int SimetricaMatriu(int M[][N_COL1], int n_fil, int n_col)
{
	int simetrica = 1;

	for (int i = 0;i < n_fil;i++)
	{
		for (int j = 0;j < n_col;j++)
		{
			if (M[i][j] != M[j][i])
			{
				simetrica = 0;
			}
		}
	}
	return simetrica;
}

int SumaValorsMatriu(int M[][N_COL1], int n_fil, int n_col)
{
	int i, j, suma = 0;

	for (i = 0;i < n_fil;i++)
	{
		for (j = 0;j < n_col;j++)
		{
			suma = suma + M[i][j];
		}
	}
	return suma;
}

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