#include <iostream>

using namespace std;

int main()
{
	int a;
	cout << "Introdueix un nombre: ";
	cin >> a;

	if (a >= 0)
		cout << "Positiu";
	else
		cout << "Negatiu";
}