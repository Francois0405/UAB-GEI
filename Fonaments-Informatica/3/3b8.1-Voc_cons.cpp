#include <iostream>

using namespace std;

int main()
{
	char lletra;
	cout << "Introdueix una lletra: ";
	cin >> lletra;

	switch (lletra)
	{
	case 'a':
	case 'e': 
	case 'i':
	case 'o':
	case 'u':
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U': cout << "Vocal";
		break;
	default: cout << "Consonant";
		break;
	}
}