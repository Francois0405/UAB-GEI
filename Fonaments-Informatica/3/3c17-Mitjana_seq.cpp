#include <iostream>

using namespace std;

int main()
{
	float num, sum, mit;
	int quant;
	sum = 0;
	quant = 0;


	cout << "Introdueix una sequencia de numeros, per acabar, introdueix un 0." << endl;
	cin >> num;
	if (num == 0)
	{
		cout << "Error: La sequencia es buida. No es pot calcular la mitjana.";

	}
	else
	{
		while (num != 0)
		{
			sum = sum + num;
			quant = quant + 1;
			cin >> num;
		}
		mit = sum / quant;
		cout << "Mitjana dels nombres de la sequencia : " << mit;
	}
	}
	
