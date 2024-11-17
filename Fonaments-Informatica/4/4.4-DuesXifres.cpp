#include <iostream>
#include "duesXifres.h"

using namespace std;


int main()
{
	int hora, minuts, segons;
	char punt;

	cout << "Introdueix hora (format hh:mm:ss): ";
	cin >> hora >> punt >> minuts >> punt >> segons;

	segons++;

	if (segons == 60) {
		segons = 0;
		minuts++;
	}
	if (minuts == 60) {
		minuts = 0;
		hora++;
	}
	if (hora == 24) {
		hora = 0;
	}


	duesXifres(hora);cout << ":";
	duesXifres(minuts); cout << ":";
	duesXifres(segons); cout << endl;
	return 0;
}