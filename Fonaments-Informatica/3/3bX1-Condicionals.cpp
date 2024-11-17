#include <iostream>

using namespace std;

int main()
{
	float a;
	cout << "Escull un valor:";
	cin >> a;
	
	if ((a < 10) && (a > 0)) 
	{
		cout << "El nombre " << a << " esta en el interval";
	}
	else
	{
		cout << "El nombre " << a << " NO esta en el interval";
	}
}