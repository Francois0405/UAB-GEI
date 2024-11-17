#include <math.h>

int equacio(int a, int b, int c, float &x1, float &x2)
{
	float discriminant;

	discriminant = (pow(b, 2) - (4 * a * c));
	if (discriminant < 0)
	{
		return 0;
	}
	else
	{
		if (discriminant == 0)
		{
			x1 = x2 = ((( - b + sqrt(discriminant)) / (2 * a)));
			return 1;

		}
		else
		{
			x1 = (((-b + sqrt(discriminant)) / (2 * a)));

			x2 = (((-b - sqrt(discriminant)) / (2 * a)));
			return 2;

		}
	}
}