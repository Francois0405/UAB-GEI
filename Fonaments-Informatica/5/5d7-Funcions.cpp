#include <iostream>
#include <math.h>
#include "funcions.h"

using namespace std;

void LlegirVertexsPoligon(TPoligon& poligon)
{
	cout << "Introdueix el numero de vertexs: ";
	cin >> poligon.n_cost;
	
	cout << "Els vèrtexs s'han d'entrar ordenats." << endl << endl;
	for (int i = 0;i < poligon.n_cost;i++)
	{
		cout << "Introdueix la posicio xy del vertex " << i << endl;
		cin >> poligon.vertex[i].x;
		cin >> poligon.vertex[i].y;
	}
}

float PerimetrePoligon(TPoligon& poligon)
{
	float perimetre=0, lencost, dx, dy;

	for (int i = 0;i < poligon.n_cost-1;i++)
	{
		dx = poligon.vertex[i+1].x - poligon.vertex[i].x;
		dy = poligon.vertex[i+1].y - poligon.vertex[i].y;
			
		lencost = sqrt(pow(dx, 2) + pow(dy, 2));

		perimetre = perimetre + lencost;
	}

	dx = poligon.vertex[0].x - poligon.vertex[poligon.n_cost-1].x;
	dy = poligon.vertex[0].y - poligon.vertex[poligon.n_cost-1].y;
	lencost = sqrt(pow(dx, 2) + pow(dy, 2));
	perimetre = perimetre + lencost;

	return perimetre;
}

