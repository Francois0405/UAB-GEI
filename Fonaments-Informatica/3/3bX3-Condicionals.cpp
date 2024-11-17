#include <iostream>

using namespace std;

int main()
{
	float a, b;
	cout << "Introdueix dos nombres: ";
	cin >> a >> b;
	
	if (a > b)
	{
		cout << "a > b";
	}
	if (a < b)
	{
		cout << "a < b";
	}
	if (a == b)
	{
		cout << "a = b";
	}
}