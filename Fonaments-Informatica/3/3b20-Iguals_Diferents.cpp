#include <iostream>

using namespace std;

int main()
{
	float a, b, c;
	cout << "Introdueix tres nombres: ";
	cin >> a >> b >> c;

	if ((a + b == c) || (b + c == a) || (a + c == b))
	{
		cout << "IGUALS";
	}
	else
	{
		cout << "DIFERENTS";
	}
}