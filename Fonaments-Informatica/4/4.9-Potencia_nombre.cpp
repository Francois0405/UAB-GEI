#include <iostream>
#include <math.h>

using namespace std;

float potencia(int x, int n) // x^n
{
	float res;

	res = float(pow(x, n));
	return res;
}


int main()
{
	float x, n;
	float res;
	
	cout << "Introdueix una base i un exponent: " << endl;
	cin >> x >> n;

	res = potencia(x, n);

	cout << "El resultat d'elevar " << x << " a la potencia " << n << " es " << res << endl;

}