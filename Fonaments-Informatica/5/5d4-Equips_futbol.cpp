#include <iostream>

using namespace std;

typedef struct {
	char equip[20];
	char ciutat[20];
	int punts;
	float pressupost;
}TEquip;

void OmplirDadesEquip(TEquip &Equip)
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
	cout << "Equip: " << Equip.equip;
	cout << "Ciutat: " << Equip.ciutat;
	cout << "Punts: "<< Equip.punts;
	cout << "Pressupost: " << Equip.pressupost;
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

int main()
{

	TEquip Equip1;
	TEquip Equip2;
	int res;

	OmplirDadesEquip(Equip1);
	OmplirDadesEquip(Equip2);

	//MostrarDadesEquip(Equip1);
	//MostrarDadesEquip(Equip2);
	
	res = CompararEquips(Equip1, Equip2);

	if (res == -1)
	{
		cout << Equip1.equip << " te menys punts a la lliga que " << Equip2.equip << endl;
	}
	else if (res == 0)
	{
		cout << Equip1.equip << " te els mateixos punts a la lliga que " << Equip2.equip << endl;
	}
	else if (res == 1)
	{
		cout << Equip1.equip << " te mes punts a la lliga que " << Equip2.equip << endl;
	}
}