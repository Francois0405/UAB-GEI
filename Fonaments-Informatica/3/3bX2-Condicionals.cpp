#include <iostream>

using namespace std;

int main()
{
	float a;
	cout << "Introdueix un nombre: ";
	cin >> a;
	
	if (a < 0)
	{
		cout << "El numero es negatiu";
	}
	if (a > 0)
	{
		cout << "El numero es positiu";
	}
	if (a == 0)
	{
		cout << "El numero es 0";
	}
}