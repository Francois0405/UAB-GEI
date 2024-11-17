#include <iostream>

#define DIM 9

using namespace std;

int main()
{
	int array[DIM];
	int i;
	bool acabat = false;

	for (i = 0;i < DIM;i++)
	{
		cout << "Introdueixi la posicio " << i + 1 << " del vector: ";
		cin >> array[i];
	}
	i = 0;
	while ((!acabat) && (i < DIM))
	{
		if (array[i] % 2 == 0)
		{
			acabat = true;
			cout << "NO TOTS SON SENARS";
		}
		i++;
	}
	if (acabat == false)
	{
		cout << "TOTS SON SENARS";
	}
}