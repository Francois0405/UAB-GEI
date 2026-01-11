#pragma once

#include <iostream>
using namespace std;


// EXERCICI 1 ////////////////////////////////////////////////////////////////

float potenciaRec(float x, int n)
{
	if (n == 0)
		return 1;
	else if (n < 0)
		return 1 / potenciaRec(x, -n);
	else
		return x * potenciaRec(x, n - 1);
}


float potencia(float x, int n)
{
	if (n == 0)
		return 1;

	bool negatiu = (n < 0);
	if (negatiu)
		n = -n;

	float resultat = 1;
	for (int i = 0; i < n; i++)
		resultat *= x;

	if (negatiu)
		resultat = 1 / resultat;

	return resultat;
}

// EXERCICI 2 ////////////////////////////////////////////////////////////////

int QueFa(int v[], int n)
{
	if (n == 0)
	{
		cout << "RESULTAT queFa n= " << n << " Retorna = " << 0 << endl;
		return 0;
	}

	cout << "RESULTAT queFa n= " << n << " Retorna = QueFa ( ";
	for (int i = 0; i < n; i++)
		cout << v[i];
	cout << " , " << n - 1 << " )  * 10 + " << v[n - 1] << endl;
	return QueFa(v, n - 1) * 10 + v[n - 1];
}

int QueFaIteratiu(int v[], int n)
{
	int resultat = 0;
	for (int i = 0; i < n; i++)
		resultat = resultat * 10 + v[i];
	return resultat;
}

// EXERCICI 3 ////////////////////////////////////////////////////////////////

int invertirNumeroRec(int n, int& potencia)
{
	if (n == 0)
		return 0;

	int ultim = n % 10;
	int resta = n / 10;

	int valorActual = ultim * potencia;

	potencia /= 10;

	return valorActual + invertirNumeroRec(resta, potencia);
}

int invertirNumero(int n)
{
	if (n == 0) return 0;

	int copia = n;
	int pot = 1;
	while (copia >= 10)
	{
		copia /= 10;
		pot *= 10;
	}

	return invertirNumeroRec(n, pot);
}
