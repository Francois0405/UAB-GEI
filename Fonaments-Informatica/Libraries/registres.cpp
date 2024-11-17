#include <iostream>
#include <string.h>

using namespace std;

void InicialitzarClassificacio(TEquip Equips[], int dim)
{
	for (int i = 0;i < dim;i++)
	{
		strcpy_s(Equips[i].ciutat, "-----");
		strcpy_s(Equips[i].equip, "-----");
		Equips[i].pressupost = 0;
		Equips[i].punts = 0;
	}
}

void MostrarClassificacio(TEquip Equips[], int dim) {
	for (int i = 0;i < dim;i++)
	{
		cout << i + 1 << ".- " << Equips[i].equip << " " << Equips[i].punts << endl;
	}
}

void DesplacarClassificacio(TEquip Equips[], int dim, int ind)
{

	for (int i = dim - 1; i > ind;i--)
	{
		Equips[i] = Equips[i - 1];
	}
}

void OmplirDadesEquip(TEquip& Equip)
{
	cout << "Introdueix les dades" << endl;
	cout << "Equip: ";
	cin >> Equip.equip;
	cout << "Ciutat: ";
	cin >> Equip.ciutat;
	cout << "Punts: ";
	cin >> Equip.punts;
	cout << "Pressupost: ";
	cin >> Equip.pressupost;
	cout << endl;
}

void MostrarDadesEquip(TEquip Equip)
{
	cout << Equip.equip << " ";
	cout << Equip.ciutat << " ";
	cout << Equip.punts << " ";
	cout << Equip.pressupost;
	cout << endl;
}

int CompararEquips(TEquip Equip1, TEquip Equip2)
{
	if (Equip1.punts < Equip2.punts)
	{
		return -1;
	}
	else if (Equip1.punts == Equip2.punts)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

// Poligons
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
	float perimetre = 0, lencost, dx, dy;

	for (int i = 0;i < poligon.n_cost - 1;i++)
	{
		dx = poligon.vertex[i + 1].x - poligon.vertex[i].x;
		dy = poligon.vertex[i + 1].y - poligon.vertex[i].y;

		lencost = sqrt(pow(dx, 2) + pow(dy, 2));

		perimetre = perimetre + lencost;
	}

	dx = poligon.vertex[0].x - poligon.vertex[poligon.n_cost - 1].x;
	dy = poligon.vertex[0].y - poligon.vertex[poligon.n_cost - 1].y;
	lencost = sqrt(pow(dx, 2) + pow(dy, 2));
	perimetre = perimetre + lencost;

	return perimetre;
}