#include <iostream>

using namespace std;

int main()
{
	char c;
	cout << "Introdueix una lletra: ";
	cin >> c;

	if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') ||
		(c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U'))
		cout << "Vocal";
	else
		cout << "Consonant";
}