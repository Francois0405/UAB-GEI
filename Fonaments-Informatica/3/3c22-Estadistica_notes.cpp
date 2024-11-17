#include <iostream>

using namespace std;

int main()
{
	int S, A, N, E, MH;
	float nota;
	S = 0;
	A = 0;
	N = 0;
	E = 0;
	MH = 0;

	cout << "Introdueix les notes de tots els alumnes de un en un, quan hagis acabat introdueix una nota inexistent." << endl;
	cin >> nota;

	while ((nota >= 0) && (nota <= 10))
	{
		if (nota < 5)
		{
			S = S + 1;
		}
		else
		{
			if (nota < 7)
			{
				A = A + 1;
			}
			else
			{
				if (nota < 9)
				{
					N = N + 1;
				}
				else
				{
					if (nota < 10)
					{
						E = E + 1;
					}
					else
					{
						MH = MH + 1;
					}
				}
			}
		}
		cin >> nota;

	}
	cout << "S: " << S << " - A: " << A << " - N: " << N << " - E: " << E << " - MH: " << MH << endl;
}
