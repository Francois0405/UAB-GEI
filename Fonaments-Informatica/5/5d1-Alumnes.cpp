#include <iostream>

using namespace std;

int main()
{

	typedef struct {
		char Nom[10];
		char Cognom1[15];
		char Cognom2[15];
		float Nota;
	} TipusAlumne;

	TipusAlumne alumne1;
	/*cout << "-- Fitxa alumne --" << endl;
	cout << "Nom: ";*/
	cin >> alumne1.Nom;
	//cout << "Cognom1: ";
	cin >> alumne1.Cognom1;
	//cout << "Cognom2: ";
	cin >> alumne1.Cognom2;
	//cout << "Nota: ";
	cin >> alumne1.Nota;

	cout << alumne1.Cognom1 << " " << alumne1.Cognom2 << ", " << alumne1.Nom << " " << alumne1.Nota;
}