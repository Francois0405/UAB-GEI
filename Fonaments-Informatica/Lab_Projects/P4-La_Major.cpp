#include "utilitats.h"
#include <iostream>

using namespace std;

int main() {
	Carta Baralla[NUM_CARTES];
	Jugador huma, maquina;
	int TopBaralla = 0, EleccioMaquina, EleccioHuma, valortot, cartesma;
	bool major;
	maquina.Punts = 0;
	huma.Punts = 0;

	InicialitzarBaralla(Baralla, PALS, NUMEROS);
	Remenar(Baralla, NUM_CARTES, 1000);
	for (TopBaralla = 0;TopBaralla < NUM_CARTES_MA;TopBaralla++)
	{
		huma.Ma[TopBaralla] = Baralla[TopBaralla];
		maquina.Ma[TopBaralla] = Baralla[TopBaralla + 3];
	}
	cartesma = 3;
	TopBaralla = 6;
	do
	{
		EleccioMaquina = IndexCartaMajor(maquina.Ma, NUM_CARTES_MA);
		EleccioMaquina = IndexCartaMajor(maquina.Ma, NUM_CARTES_MA);

		/* DEBUGGING
		//ImprimirArrayCartes(Baralla, NUM_CARTES);
		//system("PAUSE");
		cout << "DADES:" << endl;
		cout << "TopBaralla - " << TopBaralla << endl;
		cout << endl << "Ordenador: " << EleccioMaquina+1 << endl;
		ImprimirArrayCartes(maquina.Ma, NUM_CARTES_MA);
		cout << endl << "Jugador" << endl;*/

		ImprimirArrayCartes(huma.Ma, NUM_CARTES_MA);
		EleccioHuma = LlegirEnter(1, 3) - 1;
		major = MajorQue(huma.Ma[EleccioHuma], maquina.Ma[EleccioMaquina]);
		valortot = huma.Ma[EleccioHuma].Numero + maquina.Ma[EleccioMaquina].Numero;
		if (major == false)
		{
			cout << "La maquina guanya" << endl;
			maquina.Punts = maquina.Punts + valortot;
		}
		else
		{
			cout << "L'huma guanya" << endl;
			huma.Punts = huma.Punts + valortot;
		}
		cout << "Huma: " << huma.Punts << " Maquina: " << maquina.Punts << endl;
		cartesma--;
		if (cartesma < NUM_CARTES)
		{
			huma.Ma[EleccioHuma] = Baralla[TopBaralla];
			maquina.Ma[EleccioMaquina] = Baralla[TopBaralla + 1];
			TopBaralla = TopBaralla + 2;
			cartesma++;
		}

		/*while ((cartesma < NUM_CARTES_MA) && (TopBaralla < NUM_CARTES -1))
		{
			huma.Ma[EleccioHuma] = Baralla[TopBaralla + 1];
			maquina.Ma[EleccioMaquina] = Baralla[TopBaralla + 2];
			TopBaralla = TopBaralla + 2;
			cartesma++;
		}*/

	} while (TopBaralla < NUM_CARTES);

	//DEBUGGING
	/*cout << "ULTIMAS CARTES" << endl;
	cout << endl << "Ordenador: " << EleccioMaquina + 1 << endl;
	ImprimirArrayCartes(maquina.Ma, NUM_CARTES_MA);
	cout << endl << "Jugador" << endl;
	ImprimirArrayCartes(huma.Ma, NUM_CARTES_MA);*/

	maquina.Punts = maquina.Punts + maquina.Ma[0].Numero + maquina.Ma[1].Numero + maquina.Ma[2].Numero;
	huma.Punts = huma.Punts + huma.Ma[0].Numero + huma.Ma[1].Numero + huma.Ma[2].Numero;

	cout << "Huma: " << huma.Punts << " Maquina: " << maquina.Punts << endl;

	if (maquina.Punts < huma.Punts)
	{
		cout << "Ha guanyat l’huma";
	}
	else if (maquina.Punts > huma.Punts)
	{
		cout << "Ha guanyat la maquina";
	}
	else
	{
		cout << "Empat!";
	}
}