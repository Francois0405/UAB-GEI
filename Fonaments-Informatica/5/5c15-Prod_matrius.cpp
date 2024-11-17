#include <iostream>

#define N_FIL1 2
#define N_COL1 3
#define N_FIL2 3 
#define N_COL2 3
#define N_FILR 2
#define N_COLR 3

using namespace std;

void ProducteMatrius(float mat1[N_FIL1][N_COL1], float mat2[N_FIL2][N_COL2], float mat3[N_FIL1][N_COL2], int n_fil, int n_col)
{
	int i, j,k;
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

int main()
{
	int i, j;
	float mat1[N_FIL1][N_COL1], mat2[N_FIL2][N_COL2], matres[N_FIL1][N_COL2];

	cout << "Matriu 1" << endl;
	for (i = 0;i < N_FIL1;i++)
	{
		for (j = 0;j < N_COL1;j++)
		{
			cout << "Introdueix M1[" << i << "][" << j << "]: ";
			cin >> mat1[i][j];
		}
	}
	cout << endl << endl;
	cout << "Matriu 2" << endl;
	for (i = 0;i < N_FIL2;i++)
	{
		for (j = 0;j < N_COL2;j++)
		{
			cout << "Introdueix M2[" << i << "][" << j << "]: ";
			cin >> mat2[i][j];
		}
	}

	ProducteMatrius(mat1, mat2, matres, N_FIL1, N_COL2);

	cout << endl << endl;
	cout << "Matriu Resultat" << endl;
	for (i = 0;i < N_FIL1;i++)
	{
		for (j = 0;j < N_COL2;j++)
		{
			cout << matres[i][j] << " ";
		}
		cout << endl;
	}

}