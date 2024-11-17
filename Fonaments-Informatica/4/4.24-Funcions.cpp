#include <math.h>

void polars(float x, float y, float& modul, float& angle)
{
	modul = sqrt(pow(x, 2) + pow(y, 2));
	angle = atan(y / x);
}