#include <iostream>

using namespace std;

int main()
{
	float teoria, seminaris, practiques, notaF;

	cout << "Introdueix la teva nota de Teoria, la teva nota de seminaris i la teva nota de practiques: ";
	cin >> teoria >> seminaris >> practiques;

	notaF = teoria * 0.4 + seminaris * 0.3 + practiques * 0.3;
	
	cout << "La nota final es " << notaF << " - ";
	if ((notaF >= 0) && (notaF < 5))
	{ 
		cout << "SUSPES";
	}
	else
	{
		if (notaF < 7)
		{
			cout << "APROVAT";
		}
		else
		{
			if (notaF < 9)
			{
				cout << "NOTABLE";
			}
			else
			{
				if (notaF < 10)
				{
					cout << "EXCEL.LENT";
				}
				else
				{
					if (notaF == 10)
					{
						cout << "MATRICULA D'HONOR";
					}
					else
						cout << "Error de nota";
				}
			}
		}
	}

}