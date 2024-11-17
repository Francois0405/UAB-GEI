#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
#define DIM 16
int main()
{
	char cadena1[DIM], cadena2[DIM], cadena3[DIM];

	//cout << "Introdueix la primera cadena: ";
	cin >> cadena1;
	//cout << "Introdueix la segona cadena: ";
	cin >> cadena2;
	//cout << "Introdueix la tercera cadena: ";
	cin >> cadena3;

	/*gets_s(cadena1);

	gets_s(cadena2);

	gets_s(cadena3);*/

	//for (int i = 0;i < DIM-1;i++)
	//{
	//	//cout << "Introdueix la posició " << i << " de la cadena1 " << ": ";
	//	cin >> cadena1[i];
	//}
	//for (int i = 0;i < DIM-1;i++)
	//{
	//	//cout << "Introdueix la posició " << i << " de la cadena2 " << ": ";
	//	cin >> cadena2[i];
	//}
	//for (int i = 0;i < DIM-1;i++)
	//{
	//	//cout << "Introdueix la posició " << i << " de la cadena3 " << ": ";
	//	cin >> cadena3[i];
	//}
	//bool acabat = false;
	int i = 0;
	//int ind_1, ind_2, ind_3;
	/*
	while (acabat == false && i < DIM)
	{
		if (cadena1[i] == "")
		{

		}
		i++;
	}
	*/

	/*cadena1[DIM - 1] = '\0';
	cadena2[DIM - 1] = '\0';
	cadena3[DIM - 1] = '\0';*/

	cout << "Cadenes introduides: ";
	while (i < DIM && cadena1[i] != '\0')
	{
		cout << cadena1[i];
		i++;
	}
	i = 0;
	cout << " ";
	while (i < DIM && cadena2[i] != '\0')
	{
		cout << cadena2[i];
		i++;
	}
	i = 0;
	cout << " ";
	while (i < DIM && cadena3[i] != '\0')
	{
		cout << cadena3[i];
		i++;
	}
	i = 0;
	cout << endl;

	if (strcmp(cadena1, cadena2) == 0)
	{
		if (strcmp(cadena2, cadena3) == 0)
		{
			cout << "Les tres cadenes son iguals" << endl;
		}
		else
		{
			cout << "Les cadenes 1 i 2 son iguals" << endl;
		}
	}
	else if (strcmp(cadena2, cadena3) == 0)
	{
		cout << "Les cadenes 2 i 3 son iguals" << endl;
	}
	else if (strcmp(cadena1, cadena3) == 0)
	{
		cout << "Les cadenes 1 i 3 son iguals" << endl;
	}
	else
	{
		cout << "Les tres cadenes son diferents" << endl;
	}
}