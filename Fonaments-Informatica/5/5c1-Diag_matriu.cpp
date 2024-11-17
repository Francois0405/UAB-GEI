#include <iostream>

using namespace std;

#define N_FIL 4
#define N_COL 4

int main()
{
	int mat[N_FIL][N_COL];
	int f, c, d;
	for (f = 0;f < N_FIL;f++)
	{
		for (c = 0;c < N_COL;c++)
		{
			cout << "Introdueix mat[" << f << "][" << c << "]: ";
			cin >> mat[f][c];
		}
	}
	cout << "Matriu completa :)" << endl << endl;

	cout << "Diagonal de la matriu: " << endl;
	for (d = 0;d < N_FIL;d++)
	{
		cout << mat[d][d];
	}
}