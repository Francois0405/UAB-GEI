#include <iostream>
#define DIM 5

using namespace std;


int main()
{
	typedef struct {
		char Nom[10];
		char Cognom1[15];
		char Cognom2[15];
		float Nota;
	} TipusAlumnes;

	TipusAlumnes alumnes[DIM];

	for (int i = 0;i < DIM;i++)
	{
		cout << "ALUMNE " << i + 1 << endl;
		cout << "Nom: ";
		cin >> alumnes[i].Nom;
		cout << "Cognom1: ";
		cin >> alumnes[i].Cognom1;
		cout << "Cognom2: ";
		cin >> alumnes[i].Cognom2;
		cout << "Nota: ";
		cin >> alumnes[i].Nota;
	}

	for (int i = 0;i < DIM;i++)
	{
		cout << alumnes[i].Cognom1 << " " << alumnes[i].Cognom2 << ", " << alumnes[i].Nom << " " << alumnes[i].Nota << endl;
	}

}