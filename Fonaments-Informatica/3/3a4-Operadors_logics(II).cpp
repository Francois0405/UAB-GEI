#include <iostream>

using namespace std;

int main()
{
	//VAR
	bool res;
	float x, y;
	//ENT
	cout << "introdueix un valor d'x: ";
	cin >> x;
	cout << "introdueix un valor d'y: ";
	cin >> y;
	//PRO
	res = (((x > 0) && (x < 10)) && ((y > 0) && (y < 10)));
	//SOR
	cout << "El resultat es: " << res;
}