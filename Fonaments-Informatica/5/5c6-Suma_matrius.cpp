#include <iostream>

#define N_COL 3
#define N_FIL 2

using namespace std;

int SumaValorsMatriu(int M[][N_COL], int n_fil, int n_col)
{
	int i,j, suma=0;

	for (i = 0;i < n_fil;i++)
	{
		for (j = 0;j < n_col;j++)
		{
			suma = suma + M[i][j];
		}
	}
	return suma;
}

int main()
{
	int i, j, M[N_FIL][N_COL], res;

	for (i = 0;i < N_FIL;i++)
	{
		for (j = 0;j < N_COL;j++)
		{
			cout << "Introdueix M[" << i << "]" << "[" << j << "]:";
			cin >> M[i][j];
		}
	}
	cout << endl;
	res = SumaValorsMatriu(M, N_FIL, N_COL);

	cout << "Suma valors matriu: " << res << endl;
}