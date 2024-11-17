#include <iostream>

using namespace std;

int main()
{
	int num, suma, final;

	cout << "Introdueixi un numero enter positiu: " << endl;
	cin >> final;

	num = 0;
	suma = 0;

	do
	{
		do
		{
			cout << "Error: el valor ha de ser mes gran que zero" << endl;
			cout << "Introdueixi un numero enter positiu: " << endl;
			cin >> final;
		}
		while (final <= 0);
		num = num + 1;
		suma = num + suma;
	} while (num < final);

	cout << "El sumatori de " << final << " es: " << suma;
}