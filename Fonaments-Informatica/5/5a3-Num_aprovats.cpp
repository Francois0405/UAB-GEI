#include <iostream>

using namespace std;

#define DIM 20

int main()
{
	float notes[DIM];
	float nota;
	int cont_ap=0;

	cout << "Introdueixi les notes de 20 alumnes, alumne per alumne." << endl;
	for (int i = 0; i <= (DIM-1); i++)
	{
		cout << "Alumne " << i+1 << ": ";
		cin >> notes[i];
		while ((notes[i] < 0) || (notes[i] > 10))
		{
			cout << "Error: nota no valida" << endl;
			cout << "Alumne " << i + 1 << ": ";
			cin >> notes[i];
		}
	}

	for (int i = 0; i <= (DIM - 1); i++)
	{
		if (notes[i] >= 5)
			cont_ap++;
	}

	cout << "El nombre d'aprovats es: " << cont_ap << endl;

}