#include <iostream>

using namespace std;

int LongCadena(char cadena[])
{
	int i = 0, cont = 0;
	while (cadena[i] != '\0')
	{
		i++;
	}
	return i;
}

int TrobarCaracter(char string[], char caracter)
{
	int trobat = 0;
	int i = 0;

	while (trobat == 0 && string[i] != '\0')
	{

		if (string[i] == caracter)
		{
			trobat = 1;
		}
		i++;
	}
	return trobat;
}

void Majuscules(char string[]) // Totes les minuscules les passa a majuscules
{
	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] >= 97 && string[i] <= 122)
		{
			string[i] = string[i] - 32;
		}
		i++;
	}
}

int Palindrom(char string[])
{
	int i = 0, longi;
	bool palindrom = true;
	longi = strlen(string);
	cout << "La longitud de l'array es: " << longi << endl;
	while (palindrom == true && i < longi)
	{
		if (string[i] != string[longi - i - 1])
		{
			palindrom = false;
		}
		i++;
	}

	return palindrom;
}

char PrimerDiferent(char cadena1[], char cadena2[])
{
	char caracter;
	int len1 = strlen(cadena1);
	int len2 = strlen(cadena2);
	bool diferent = false;
	int i = 0;

	while (diferent == false && cadena1[i] != 0 && cadena2[i] != 0)
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