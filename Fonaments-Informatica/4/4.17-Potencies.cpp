#include <iostream>

using namespace std;

void potencies(int a, int b) // a = exponent | b = limit
{
	for (int pot = 1;pot <= b; pot = pot * a)
		cout << pot << " ";
}

int main()
{
	int exp, lim;
	cout << "Introdueix dos valors enters, la potencia i el limit: " << endl;
	cin >> exp >> lim;

	if ((exp > 1) && (lim > exp))
	{
		potencies(exp, lim);
	}
	else
		cout << "Error: Valors incorrectes" << endl;
}