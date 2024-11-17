#include <iostream>

using namespace std;

int main()
{
	int anyN, m;

	cout << "Quin es l'any del teu naixement: ";
	cin >> anyN;
	
	m = anyN % 12;

		switch (m)
		{
		case 0: cout << "Signe: mono";
			break;
		case 1: cout << "Signe: gall";
			break;
		case 2: cout << "Signe: gos";
			break;
		case 3: cout << "Signe: porc";
			break;
		case 4: cout << "Signe: rata";
			break;
		case 5: cout << "Signe: bou";
			break;
		case 6: cout << "Signe: tigre";
			break;
		case 7: cout << "Signe: conill";
			break;
		case 8: cout << "Signe: drac";
			break;
		case 9: cout << "Signe: serp";
			break;
		case 10: cout << "Signe: cavall";
			break;
		case 11: cout << "Signe: cabra";
			break;
		}
}