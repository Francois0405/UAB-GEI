#include <iostream>

using namespace std;

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