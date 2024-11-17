#include <iostream>

using namespace std;

int main()
{
	int valor;

	cout << "Introdueixi un valor enter: ";

	cin >> valor;

	int array[10];

	for (int i = 0; i < 10; i++)
	{
		array[i] = valor;
		cout << array[i] << endl;
	}
}