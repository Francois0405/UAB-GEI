#include <iostream>
#include <string.h>

using namespace std;

int Palindrom(char string[])
{
	int i=0, longi;
	bool palindrom = true;
	longi = strlen(string);
	cout << "La longitud de l'array es: " << longi << endl;
	while (palindrom==true && i< longi)
	{
		if (string[i] != string[longi - i-1])
		{
			palindrom = false;
		}
		i++;
	}

	return palindrom;
}