#include <iostream>

using namespace std;

/*
Majuscules	65-90
	Diff (+32)
Minuscules	97-122
*/
void Majuscules(char string[]) // Totes les minuscules les passa a majuscules
{
	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] >= 97 && string[i] <=122)
		{
			string[i] = string[i] - 32;
		}
		i++;
	}
}

int main()
{
	char string[50];
	cout << "Introdueix una cadena de caracters: ";
	cin >> string;
	Majuscules(string);
	cout << "La cadena en majuscules es: ";
	cout << string << endl;
}