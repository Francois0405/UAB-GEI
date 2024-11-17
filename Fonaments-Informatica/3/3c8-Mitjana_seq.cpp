#include <iostream>

using namespace std;

int main()
{
	int quantitat, num, suma;
	float mitjana;
	
	suma = 0;
	quantitat = 0;

	cout << "Introdueix nombres per a calcular la mitjana. Quan introdueixis 0, la sequencia acaba.";
	cin >> num;

	if (num == 0)
	{
		cout << " Error: La sequencia es buida. No es pot calcular la mitjana." << endl;
	}
	else
	{
		do
		{
			quantitat = quantitat + 1;
			suma = num + suma;
			cin >> num;
		} while (num != 0);

		mitjana = float(suma) / quantitat;

		cout << "Mitjana dels nombres de la sequencia : " << mitjana;
	}
}