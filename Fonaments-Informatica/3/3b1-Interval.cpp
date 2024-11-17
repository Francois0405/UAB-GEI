#include <iostream>

using namespace std;

int main()
{
	int a;
	cout << "Nombre: ";
	cin >> a;
	if ((a >= 0) && (a <= 10))
	{
		cout << "El nombre " << a << " esta en l'interval";
	}
	else
	{
		cout << "El nombre " << a << " NO esta en l'interval";
	}
}