#include <iostream>

using namespace std;

#define DIM 15

int main() {
	
	int array[DIM];
	int n = 1;
	int sum = 0, quant = 0;
	float mitj;

	for (int i=0; i < DIM; i++)
	{
		cout << "Introdueix els mesos que tenia el/la nen/a " << n << " quan va caminar per primer cop : ";
		cin >> array[i];
		while ((array[i] < 9) || (array[i] > 18))
		{
			cout << "Error: Valor no valid" << endl;
			cin >> array[i];
		}
		n++;
	}
	for (int i = 0;i < DIM; i++)
	{
		quant++;
		sum = sum + array[i];
	}
	mitj = float(sum) / quant;

	cout << "Mitjana d'edat en caminar: " << mitj << " mesos" << endl;
}