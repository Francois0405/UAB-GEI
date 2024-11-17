#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int num_s, num, intents;
	bool acabat;
	char replay;
	intents = 0;
	do {
		num_s = (rand() % 10) + 1;

		//
		acabat = false;
		do {
			cout << "Intenta endevinar el meu numero (1 al 10): " << endl;
			cin >> num;
			if ((num >= 1) && (num <= 10))
			{
				intents++;
				if (num < num_s)
				{
					cout << "El numero a endevinar es mes gran" << endl;
				}
				else
				{
					if (num > num_s)
					{
						cout << "EL numero a endevinar es mes petit" << endl;
					}
					else
					{
						cout << "Has guanyat!!! Has encertat en " << intents << " intents" << endl;
						acabat = true;
					}
				}
			}
			else
			{
				cout << "Error: Valor fora del rang 1-10" << endl;
			}
		} while (intents < 5 && acabat != true);
		if (acabat != true)
		{
			cout << "Has perdut: El numero secret era " << num_s << endl;
			acabat = true;
		}
		// Tornar a jugar?
		cout << "Vols tornar a jugar?" << endl;
		cin >> replay;
		intents = 0;
	} while (replay == 'S' || replay == 's');
}