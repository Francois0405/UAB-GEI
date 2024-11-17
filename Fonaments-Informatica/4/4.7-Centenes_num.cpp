#include <iostream>

using namespace std;

int centenes(int num)
{
	int cent;

	cent = (num / 100) % 10;

	return cent;
}

int main()
{
	int num, cent;

	cout << "Introdueix un nombre: ";
	cin >> num;

	cent = centenes(num);

	cout << "Les centenes del nombre " << num << " son " << cent;
}