#include <iostream>
#include "funcions.h"
#include <string.h>

#define N_EQUIPS 5

using namespace std;

int main()
{
	TEquip Equips[N_EQUIPS];
	char opcio;
	int ind;

	InicialitzarClassificacio(Equips, N_EQUIPS);
	do {
		MostrarClassificacio(Equips,N_EQUIPS);
		cout << "On vols inserir l'equip?" << endl;
		cin >> ind;
		DesplacarClassificacio(Equips, N_EQUIPS, ind-1);
		OmplirDadesEquip(Equips[ind-1]);
		cout << "Vols inserir un altre equip? S/-" << endl;
		cin >> opcio;
	} while (opcio == 'S' || opcio == 's');

	MostrarClassificacio(Equips, N_EQUIPS);

}