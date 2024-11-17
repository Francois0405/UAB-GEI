#include <iostream>

using namespace std;

int main()
{
	int max, min, n, quant, producte;
	float suma, mitjana;
	cout << "Introdueix un rang de valors, el principi i el final: " << endl;
	cin >> min >> max;
	n = min;
	suma = 0;
	producte = 1;
	quant = 0;

	for (n = min; n <= max; n++)
	{
		if (n % 2 == 0)
		{
			suma = suma + n;
			producte = producte * n;
			quant = quant + 1;
		}
	}
	mitjana = suma / quant;
	cout << "Suma: " << suma << " - Producte: " << producte << " - Mitjana: " << mitjana;
}