#include <iostream>

using namespace std;

#define DIM 10

int main()
{
	int array[DIM];
	bool acabat=false; 
	int i, guardar;

	for (i = 0; i < DIM; i++)
	{
		cout << "Introdueix el index " << i << ": ";
		cin >> array[i];
	}

	i = 0;
	while ((i<DIM-1)&&(! acabat))
	{
		if (array[i + 1] < array[i])
		{
			acabat = true;
		}
		else
		{
			i++;
		}

		//if (array[i + 1] < array[i]) PARA SUSTITUIR DENTRO DEL ARRAY
		{
			//guardar = array[i+1];
			//array[i + 1] = array[i];
			//array[i] = guardar;
			//i = 0;
		}
		//else
		{
			//i++;
		}
	}
	cout << i;
	for (i = 0;i < DIM;i++)
	{
		cout << "Index " << i << endl;
		cout << array[i] << endl;
	}
}