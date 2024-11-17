#include <iostream>
#include "polars.h"

using namespace std;

int main()
{
	float x, y, modul, angle;

	cout << "Introdueix una x i una y: " << endl;
	cin >> x >> y;
	
	polars(x, y, modul, angle);

	cout << "Modul: " << modul << " - Angle: " << angle;
	return 0;
}