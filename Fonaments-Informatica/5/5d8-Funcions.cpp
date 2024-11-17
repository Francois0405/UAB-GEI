#include <iostream>
#include "funcions.h"
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
		cout << i+1 << ".- " << Equips[i].equip << " " << Equips[i].punts << endl;
	}
}

void DesplacarClassificacio(TEquip Equips[], int dim, int ind)
{
	
	for (int i = dim-1; i >ind;i--)
	{
		Equips[i] = Equips[i-1];
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