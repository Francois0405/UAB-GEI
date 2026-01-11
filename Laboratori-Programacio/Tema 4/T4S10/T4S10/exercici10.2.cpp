#pragma once

#include <iostream>
using namespace std;


// EXERCICI 1 ////////////////////////////////////////////////////////////////

float potenciaRec(float x, int n)
{
	if (n == 0) return 1;
	if (n == 1) return x;
	else if (n < 0)
	{
		n = -n;
		return 1 / potenciaRec(x, n);
	}
	float res = x * potenciaRec(x, n - 1);
	return res;
}

float potencia(float x, int n)
{
	bool neg = false;
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	else if (n < 0)
	{
		neg = true;
		n = -n;
	}
	float res = x;
	for (int i = 1; i < n; i++)
		res = x * res;
	if (neg)
		res = 1 / res;
	return res;
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

int   QueFaIteratiu(int v[], int n)
{
	// A MODIFICAR
	return 0;
}

// EXERCICI 3 ////////////////////////////////////////////////////////////////

int invertirNumeroRec(int n, int& potencia)
{
	// A MODIFICAR
	return 0;
}

int invertirNumero(int n)
{
	// A MODIFICAR
	// Crida a invertirNumeroRec()
	return 0;
}
