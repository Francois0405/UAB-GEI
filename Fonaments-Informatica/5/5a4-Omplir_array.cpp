#include <iostream>

using namespace std;

#define DIM 10

int main()
{
	int array[DIM];
	int ind=0;
	bool acabat=false;

	while ((ind < DIM) && !acabat)
	{
		cout << "Introdueix el valor de l'array a l'index " << ind << ": " << endl;
		cin >> array[ind];
		if (array[ind] == 0)
		{
			acabat = true;
		}
		ind++;
	}
	if (acabat == true)
	{
		cout << "Hem introduit un zero" << endl;
	}
	else
	{
		cout << "Hem arribat al final de l'array" << endl;
	}
}