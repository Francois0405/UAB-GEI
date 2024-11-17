#include <iostream>

using namespace std;

int main()
{
	float sal;
	int anys;
	cout << "Introdueix el teu salari base i a continuació els anys que portes a l'empresa: ";
	cin >> sal >> anys;

	if (anys < 3)
	{
		sal = sal * 1.01;
	}
	else
	{
		if (anys < 5)
			sal = sal * 1.02;
		else
			sal = sal * 1.035;
	}
	cout << "El salari final es: " << sal;
}