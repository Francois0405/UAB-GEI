#include <iostream>

using namespace std;

int main()
{
	int num1, num2, a, b;

	cout << "Introdueix dos nombres enters: " << endl;
	cin >> num1 >> num2;
	a = num1;	
	b = num2;
	
	if (num1 > num2)
	{
		num1 = b;
		num2 = a;
	}
	cout << "El valor de num1 es " << num1 << " i el valor de num2 es " << num2;
}