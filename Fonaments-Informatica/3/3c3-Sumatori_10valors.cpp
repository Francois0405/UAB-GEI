#include <iostream>

using namespace std;

int main() 
{
	float sum, num;
	sum = 0;
	num = 0;

	while (num <= 10)
	{
		sum = num + sum;
		num = num + 1;
	}
	
	cout << "El resultat del sumatori es: " << sum;
}