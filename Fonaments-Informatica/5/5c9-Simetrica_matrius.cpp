#include <iostream>

using namespace std;

#define N_COL 3
#define N_FIL 3

int SimetricaMatriu(int M[][N_COL],int n_fil,int n_col)
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

int main()
{
	int M[N_FIL][N_COL], res;

	for (int i = 0;i < N_FIL;i++)
	{
		for (int j = 0;j < N_COL;j++)
		{
			cout << "Introdueix M[" << i << "][" << j << "]: ";
			cin >> M[i][j];
		}
	}

	res = SimetricaMatriu(M, 3, 3);

	if (res == 1)
	{
		cout << "MATRIU SIMETRICA" << endl;
	}
	else
	{
		cout << "MATRIU NO SIMETRICA" << endl;
	}
}