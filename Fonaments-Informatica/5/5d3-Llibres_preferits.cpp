#include <iostream>

using namespace std;

int main()
{
	typedef struct {
		char titol[40];
		char editorial[40];
		int pagines;
		float preu;
	} TLlibre;

	TLlibre llibre1;
	TLlibre llibre2;

	cout << "-- Llibre favorit 1 --";
	cout << "Titol: ";
	cin >> llibre1.titol;
	cout << "Editorial: ";
	cin >> llibre1.editorial;
	cout << "Pagines: ";
	cin >> llibre1.pagines;
	cout << "Preu: ";
	cin >> llibre1.preu;

	cout << "-- Llibre favorit 2 --";
	cout << "Titol: ";
	cin >> llibre2.titol;
	cout << "Editorial: ";
	cin >> llibre2.editorial;
	cout << "Pagines: ";
	cin >> llibre2.pagines;
	cout << "Preu: ";
	cin >> llibre2.preu;

	cout << endl;

	cout << "Llibres preferits:" << endl;
	cout << llibre1.titol << " " << llibre1.editorial << " " << llibre1.pagines << " " << llibre1.preu << endl;
	cout << llibre2.titol << " " << llibre2.editorial << " " << llibre2.pagines << " " << llibre2.preu << endl;
}