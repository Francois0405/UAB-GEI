#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	float num_s, num;
	int intents;
	bool acabat;
	char replay;
	acabat = false;
	intents = 0;
	num_s = (rand() % 10) + 1;

	
	do
	{
		if (intents < 5)
		{
			cout << "Intenta endevinar el meu numero (1 al 10): " << endl;
			cin >> num;
			if ((num >= 1) && (num <= 10))
			{
				if (num < num_s)
				{
					cout << "El numero a endevinar es mes gran" << endl;
					intents++;
				}
				else
				{
					if (num > num_s)
					{
						cout << "EL numero a endevinar es mes petit" << endl;
						intents++;
					}
					else
					{
						intents++;
						cout << "Has guanyat !!! Has encertat en " << intents << " intents" << endl;
						acabat = true;
					}
				}
			}
			else
			{
				cout << "Error: Valor fora del rang 1-10" << endl;
			}
		}
		else
		{
			cout << "Has perdut : El numero secret era " << num_s << endl;
			acabat = true;
		}

		if (acabat == true)
		{
			cout << "Vols tornar a jogar? [S/N]: " << endl;
			cin >> replay;
			if (replay == 'S')
			{
				acabat = false;
				intents = 0;
			}
			else
			{
				if (replay == 'N')
				{
					acabat = true;
				}
			}
		}
	} while (acabat == false);
}