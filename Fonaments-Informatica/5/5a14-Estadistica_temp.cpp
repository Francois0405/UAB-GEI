#include <iostream>

using namespace std;

int main()
{
	int temp_min, temp_max, mes_max=1, mes_min=1;
	int mesos[12], relativa[12];
	float mitjana;
	int sum=0, quant=0;

	for (int i = 0; i < 12;i++)
	{
		//cout << "Temperatura del mes " << i + 1 << ": ";
		cin >> mesos[i];
		quant++;
		sum = sum + mesos[i];
	}
	temp_max = mesos[0];
	temp_min = mesos[0];
	mitjana = float(sum) / quant;
	for (int i = 0; i < 12; i++)
	{
		if (mesos[i] > temp_max)
		{
			temp_max = mesos[i];
			mes_max = i + 1;
		}
		if (mesos[i] < temp_min)
		{
			temp_min = mesos[i];
			mes_min = i + 1;
		}
		// 0 <, 1 =, 2 >
		if (mesos[i] < mitjana)
		{
			relativa[i] = 0;
		}
		else {
			if (mesos[i] == mitjana) {
				relativa[i] = 1;
			}
			else {
				relativa[i] = 2;
			}
		}
	}
	cout << "Mes amb temperatura minima: " << mes_min << endl;
	cout << "Mes amb temperatura maxima: " << mes_max << endl;
	cout << "Temperatura mitjana: " << mitjana << endl;
	for (int i = 0; i < 12; i++)
	{
		switch (relativa[i])
		{
		case 0:	cout << "El mes " << i + 1 << " ha tingut temperatura inferior a la mitjana anual." << endl;
			break;
		case 1: cout << "El mes " << i + 1 << " ha tingut temperatura igual a la mitjana anual." << endl;
			break;
		case 2: cout << "El mes " << i + 1 << " ha tingut temperatura superior a la mitjana anual." << endl;
			break;
		default:
			break;
		}
	}
}