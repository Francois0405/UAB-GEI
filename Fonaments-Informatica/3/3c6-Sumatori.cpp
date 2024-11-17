#include <iostream>

using namespace std;

int main()
{
	int n ,i, sum;
	sum = 0;

	cout << "Introdueix un numero a fer el sumatori: " << endl;
	cin >> n;

	while (n <= 0)
	{
		cout << "Error: el valor ha de ser mes gran que zero" << endl;
		cout << "Torna a introduir un nombre: ";
		cin >> n;
	}
	for (i = 0; i <= n; i++)
	{
		sum = i + sum;
	}
	cout << "El sumatori de " << n << " es: " << sum << endl;
}