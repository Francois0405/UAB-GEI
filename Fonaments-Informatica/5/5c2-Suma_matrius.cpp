#include "matrius.h"
#include <iostream>
using namespace std;

int main()
{
	int mat1[N_FIL][N_COL], mat2[N_FIL][N_COL], matres[N_FIL][N_COL];
	LlegirMat(mat1, N_FIL, N_COL);
	LlegirMat(mat2, N_FIL, N_COL);
	SumarMat(mat1, mat2, matres, N_FIL, N_COL);
	EscriureMat(matres, N_FIL, N_COL);
}