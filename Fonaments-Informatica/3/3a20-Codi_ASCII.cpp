#include <iostream>

using namespace std;

int main()
{
	int x, y, z;
	char a, b, c;
	cout << "Introdueix un numero del 1 al 200: ";
	cin >> x;
	if ((x > 200) || (x < 1))
	{
		cout << "Error";
	}
	a = x;
	y = x + 1;
	b = y;
	z = x + 10;
	c = z;
	cout << a << " " << b << " " << c;
}