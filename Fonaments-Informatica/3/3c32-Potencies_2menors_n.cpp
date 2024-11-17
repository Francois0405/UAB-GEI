#include <iostream>

using namespace std;

int main()
{
	int n;

	cout << "Introdueixi un nombre: ";
	cin >> n;
	for (int potencia = 1;potencia <= n; potencia = potencia * 2)
	{
		cout << potencia << " ";
	}
}