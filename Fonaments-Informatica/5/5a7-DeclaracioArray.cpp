#include <iostream>

using namespace std;

#define DIM 10

int main()
{
	int v1[DIM] = { 0,1,2,3,4,5,6,7,8,9 };
	int v2[DIM], v3[DIM], v4[DIM];
	int a;

	for (int i = 0; i < DIM; i++)
	{
		v2[i] = 2 * i;
		cout << "Introdueixi un valor enter per l'index " << i << " de l'array del tercer vector: ";
		cin >> a;
		v3[i] = a;
		v4[i] = v1[i] + v2[i] + v3[i];
	}
	
	for (int x = 1; x <= 4; x++)
	{
		cout << "Vector " << x << ": ";
		for (int i = 0; i < DIM; i++)
		{
			switch (x)
			{
			case 1: cout << v1[i] << " ";
				break;
			case 2: cout << v2[i] << " ";
				break;
			case 3: cout << v3[i] << " ";
				break;
			case 4: cout << v4[i] << " ";
				break;
			}
		}
	}
	cout << endl;
}