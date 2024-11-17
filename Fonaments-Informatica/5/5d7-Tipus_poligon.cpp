#include <iostream>
#include "funcions.h"

using namespace std;

int main()
{
	TPoligon poligon;
	float perimetre;

	LlegirVertexsPoligon(poligon);

	perimetre = PerimetrePoligon(poligon);

	cout << "Perimetre del poligon: " << perimetre << endl;
}