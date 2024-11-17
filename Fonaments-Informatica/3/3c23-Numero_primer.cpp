#include <iostream>

using namespace std;

int main()
{
	int num, div;	
	bool noprimer = false;

	cout << "Introdueix un nombre: " << endl;
	cin >> num;
	div = 2;
	if (num > 1)
	{
		while (div <= num/2)
		{
			if (num % div == 0)
				noprimer = true;
			div++;
		}
		if (noprimer == true)
			cout << "NO PRIMER" << endl;
		else
			cout << "PRIMER" << endl;
	}
	else
	{
		cout << "NO PRIMER" << endl;
	}
}