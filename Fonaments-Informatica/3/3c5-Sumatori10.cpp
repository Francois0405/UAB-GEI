#include <iostream>

using namespace std;

int main()
{
	int i, sum;
	sum = 0;
	i = 0;

	cout << "El sumatori de 10 es: ";

	for (int i = 0; i <= 10; i++) {
		sum = i + sum;
	}
	cout << sum << endl;

}