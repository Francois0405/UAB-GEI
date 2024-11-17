#include <iostream>
#include "vectors.h"

using namespace std;

int main()
{
	int temp_min, temp_max, mes_max = 1, mes_min = 1;
	int mesos[12];
	float mitjana;

	LlegirVector(mesos, 12);
	mes_max = MaximVector(mesos, 12)+1;
	mes_min = MinimVector(mesos, 12)+1;
	mitjana = MitjanaVector(mesos, 12);

	cout << "Mes amb temperatura minima: " << mes_min << endl;
	cout << "Mes amb temperatura maxima: " << mes_max << endl;
	cout << "Temperatura mitjana: " << mitjana << endl;
	for (int i = 0; i < 12; i++)
	{
		if (mesos[i] > mitjana)
		{
			cout << "El mes " << i + 1 << " ha tingut temperatura superior a la mitjana anual." << endl;
		}
		else {
			if (mesos[i] < mitjana)
			{
				cout << "El mes " << i + 1 << " ha tingut temperatura inferior a la mitjana anual." << endl;
			}
			else {
				cout << "El mes " << i + 1 << " ha tingut temperatura igual a la mitjana anual." << endl;
			}
		}
	}
}