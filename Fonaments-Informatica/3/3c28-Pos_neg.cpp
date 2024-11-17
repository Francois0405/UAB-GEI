#include <iostream>

using namespace std;

int main()
{
	int i, n, neg, pos;
	pos = 0;
	neg = 0;

	cout << "Introdueixi 5 numeros: ";
	i = 1;
	for (i = 1; i <= 5; i++)
	{
		cin >> n;
		if (n > 0)
			pos = pos + 1;
		if (n < 0)
			neg = neg + 1;
	}
	cout << "Positius: " << pos << " - Negatius: " << neg << endl;
}

