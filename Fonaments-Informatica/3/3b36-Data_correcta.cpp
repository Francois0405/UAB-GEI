#include <iostream>

using namespace std;

int main()
{
	int d, m, y;
	int diesf;
	char separador;

	cout << "Introdueix la data en format (DD/MM/YYYY): ";
	cin >> d >> separador >> m >> separador >> y;

	// 1-31, 2-28, 3-31, 4-30, 5-31, 6-30, 7-31, 8-31, 9-30, 10-31, 11-30, 12-31
	
	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
	{
		diesf = 29;
	}
	else
	{
		diesf = 28;
	}

	switch (m)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((d >= 0) && (d <= 31))
			cout << "Data correcta";
		else
			cout << "Error: Dia incorrecte";
	}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((d >= 0) && (d <= 30))
			cout << "Data correcta";
		else
			cout << "Error: Dia incorrecte";
	}
	break;
	case 2:
	{
		if ((d >= 0) && (d <= diesf))
			cout << "Data correcta";
		else
			cout << "Error: Dia incorrecte";
	}
	break;
	default: cout << "Error: Mes incorrecte";
		break;
	}
}