#include <iostream>
#include <math.h>

using namespace std;

float divisio(float a, float b)
{
	float div = 0;
	
	//div = a / b;
	bool negatiu = false;
	if ((a < 0 && b > 0) || (a > 0 && b < 0)) 
	{
		negatiu = true;
	}

	a = abs(a);
	b = abs(b);

	while (a >= b) {
		a = a - b; //a-=b;
		div++;
	}
	if (negatiu) {
		div = -div;
	}

	return div;
}

int main()
{
	float dividend, divisor, resultat;

	cout << "Introdueix un dividend i un divisor: " << endl;
	cin >> dividend >> divisor;

	if (divisor != 0)
	{
		resultat = divisio(dividend, divisor);
		cout << dividend << " : " << divisor << " = " << resultat;
	}
	else
	{
		cout << "Error: Divisio per zero" << endl;
	}
}