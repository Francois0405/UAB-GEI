#include "Operacions.h"
#include "Recta.h"

void distancia(Punt llistaPunts[], int nPunts, float distancies[])
{
	if (nPunts < 2)
		return;

	Recta r1(llistaPunts[0], llistaPunts[1]);
	if (nPunts < 3)
		return;
	int i = 2;
	int dist = 0;
	while (i < nPunts)
	{
		distancies[dist] = r1 - llistaPunts[i];
		dist++;
		i++;
	}
}

