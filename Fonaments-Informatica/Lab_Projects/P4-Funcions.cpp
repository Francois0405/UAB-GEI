#include "utilitats.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void InicialitzarBaralla(Carta Baralla[], int Pals, int Numeros)
{
	int i, j;
	for (i = 0;i < Pals;i++) // Nº Pals (4)
	{
		for (j = 0;j < Numeros;j++) // Nº Cartes (48)
		{
			// [0-11], [12-23], [24-35], [36-47]
			Baralla[j + i * Numeros].Pal = i + 1;
			Baralla[j + i * Numeros].Numero = j + 1;
		}
	}
}

void ImprimirCarta(Carta Cartes)
{
	switch (Cartes.Numero)
	{
	case AS: cout << "As";
		break;
	case SOTA: cout << "Sota";
		break;
	case CAVALL: cout << "Cavall";
		break;
	case REI: cout << "Rei";
		break;
	default:
		cout << Cartes.Numero;
		break;
	}

	cout << " de ";

	switch (Cartes.Pal)
	{
	case BASTOS: cout << "Bastos" << endl;
		break;
	case COPES: cout << "Copes" << endl;
		break;
	case ESPASES: cout << "Espases" << endl;
		break;
	case ORS: cout << "Ors" << endl;
		break;
	default:
		cout << Cartes.Pal << endl;
		break;
	}
}

void ImprimirArrayCartes(Carta aCartes[], int nCartes)
{
	int i;
	for (i = 0;i < nCartes;i++)
	{
		ImprimirCarta(aCartes[i]);
	}
}

void Intercanviar(Carta& carta1, Carta& carta2)
{
	Carta guardar;
	guardar.Numero = carta1.Numero;
	guardar.Pal = carta1.Pal;

	carta1.Numero = carta2.Numero;
	carta1.Pal = carta2.Pal;

	carta2.Numero = guardar.Numero;
	carta2.Pal = guardar.Pal;
}

int Aleatori(int NumMin, int NumMax)
{
	int NumAleatori;

	NumAleatori = NumMin + (rand() % (NumMax - NumMin + 1));

	return NumAleatori;
}

void Remenar(Carta Baralla[], int nCartes, int NumIntercanvis)
{
	int al1, al2;
	for (int i = 0;i < NumIntercanvis;i++)
	{
		al1 = Aleatori(0, nCartes - 1);
		al2 = Aleatori(0, nCartes - 1);
		Intercanviar(Baralla[al1], Baralla[al2]);
	}
}

bool MajorQue(Carta Carta1, Carta Carta2)
{
	bool Major = false;
	// Major true(carta1) false(carta2)
	if (Carta1.Numero > Carta2.Numero)
	{
		Major = true;
	}
	else if (Carta1.Numero < Carta2.Numero)
	{
		Major = false;
	}
	else if (Carta1.Pal > Carta2.Pal)
	{
		Major = true;
	}
	else if (Carta1.Pal < Carta2.Pal)
	{
		Major = false;
	}
	return Major;
}

int IndexCartaMajor(Carta aCartes[], int nCartes)
{
	int i = 0, index = 0;
	bool major;
	// Major true(carta1) false(carta2)
	major = MajorQue(aCartes[i], aCartes[i + 1]);
	if (major == true) // Si la segunda es pequeña comparamos 1 y 3
	{
		major = MajorQue(aCartes[i], aCartes[i + 2]);
		if (major == true)
		{
			index = i;
		}
		else index = i + 2;
	}
	else // Si la primera es pequeña, comparamos 2 y 3
	{
		major = MajorQue(aCartes[i + 1], aCartes[i + 2]);
		if (major == true)
		{
			index = i + 1;
		}
		else index = i + 2;
	}
	return index;
}

int LlegirEnter(int min, int max)
{
	int al, carta;
	al = Aleatori(min, max);

	cout << "Entra la carta que vols escollir: ";
	cin >> carta;

	while (carta < min || carta > max)
	{
		cout << "Error: Seleccio incorrecta";
		cin >> carta;
	}
	return carta;
}