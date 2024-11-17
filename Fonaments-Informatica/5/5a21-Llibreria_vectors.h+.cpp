#include <iostream>
#include "vectors.h"

using namespace std;

int main() {
	int vector[8], minimvectornozero;

	LlegirVector(vector, 8);

	minimvectornozero = MinimVectorNoZero(vector, 6);

	cout << minimvectornozero;
}