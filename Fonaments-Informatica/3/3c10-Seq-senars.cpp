#include <iostream>

using namespace std;

int main()
{
	// Parell	=	num % 2 == 0
	// Senar	=	num % 2 == 1  (o != 0)
	// Hi ha algun nombre parell?
	
	//  

	int num;
	bool parell = false;

		do
		{
			// Solicitar al usuario que ingrese un n�mero
			cout << "Introdueixi un numero (0 per acabar): ";
			cin >> num;

			// Verificar si el n�mero es par (distinto de cero)
			if (num % 2 == 0 && num != 0)
			{
				parell = true;  // Encontramos al menos un n�mero par
			}

		} while (num != 0);

		if (parell == true)
		{
			cout << "Algun nombre de la sequencia es parell.";
		}
		else
		{
			cout << "No hi ha cap nombre parell en la sequencia.";
		}
}