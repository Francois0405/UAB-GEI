#include <iostream>
#include <string.h>

using namespace std;

char PrimerDiferent(char cadena1[], char cadena2[])
{
	char caracter;
	int len1 = strlen(cadena1);
	int len2 = strlen(cadena2);
	bool diferent = false;
	int i = 0;

	while (diferent==false && cadena1[i] != 0 && cadena2[i] !=0)
	{
		if (cadena1[i] == cadena2[i])
		{
			i++;
		}
		else
		{
			diferent = true;
			caracter = cadena1[i];
		}
	}

	if (diferent == false)
	{
		caracter = '\0';
	}
	return caracter;
}

int main()
{
	char cadena1[20], cadena2[20], caracter;

	cout << "Introdueix cadena1: ";
	cin >> cadena1;
	cout << "Introdueix cadena2: ";
	cin >> cadena2;
	
	caracter = PrimerDiferent(cadena1, cadena2);

	if (caracter == 0)
	{
		cout << "No hi ha cap caracter diferent" << endl;
	}
	else
	{
		cout << "El primer caracter diferent es " << caracter << endl;
	}
}