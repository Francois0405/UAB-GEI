#include <iostream>
#include "funcions.h"

using namespace std;

int main()
{
	char string[40];
	int res;

	cout << "Introdueix un string: ";
	cin >> string;

	res = Palindrom(string);
	
	if (res == 1)
	{
		cout << "Palindrom" << endl;
	}
	else if (res == 0)
	{
		cout << "No Palindrom" << endl;
	}
}