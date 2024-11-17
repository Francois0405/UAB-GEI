#include <iostream>

using namespace std;

int main()
{
	int x, y, z;
	bool resa, resb, resc;
	cout << "Introdueix tres valors: ";
	cin >> x >> y >> z;

	resa = (x < 7) && ((y > z) || (7 > z));

	resb = (((x == 'c') && (y < -5)) && ((z >= 100) || (z < 6)));

	resc = ((9 >= x) && (13 < y)) || (-36 >= z);

	cout << "Resultat de les expressions: " << resa << " " << resb << " " << resc;

}