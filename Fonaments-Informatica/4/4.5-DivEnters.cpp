#include "DivisioEnters.h"
// Escriure a partir d aqui la funcio DivisioEnters
int DivisioEnters(int dividend, int divisor, int &res)
{
	if (divisor != 0)
	{
		res = dividend / divisor;
		return(1);
	}
	else
	{
		return(0);
	}
}

