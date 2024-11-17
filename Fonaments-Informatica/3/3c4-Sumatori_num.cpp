#include <iostream>

using namespace std;

int main()
{
	int N;
	float sum, num;
	sum = 0;
	num = 1;

	cout << "Introdueixi un sumatori: " << endl;
	cin >> N;

	while (N <= 0)
	{
	cout << "Error: el valor ha de ser mes gran que zero" << endl;
	cout << "Torni a introdueixi un sumatori: " << endl;
	cin >> N;
	}
	
	while (num <= N)
	{
		sum = sum + num;
		num++;
	}
		
	cout << "El sumatori de " << N << " es: " << sum;
}