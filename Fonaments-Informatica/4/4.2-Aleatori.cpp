#include <iostream>
#include <cstdlib>

using namespace std;

int Aleatori(int min, int max)
{
	int al;

	al = (rand() % (max - min + 1 )) + min;

	return al;
}

int main()
{
	int min, max;
	int valor_al;

	cout << "Introdueix un rang de nombres: ";
	cin >> min >> max;

	valor_al = Aleatori(min, max);
	
	cout << "valor aleatori: " << valor_al << endl;
	system("PAUSE");
}