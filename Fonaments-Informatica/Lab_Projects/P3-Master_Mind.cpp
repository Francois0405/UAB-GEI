#include "FuncionsMasterMind.h"
#include <iostream>

using namespace std;

int main() {
	int opcio, resultat;
	srand((unsigned)time(NULL));
	do {
		Menu();

		cin >> opcio;

		switch (opcio)
		{
		case 1: // Ajuda
			Ajuda();
			break;

		case 2: // Jugar
			resultat = JocMasterMind();
			ImprimirResultatsJoc(resultat);
			break;

		case 3: // Sortir
			break;

		default:
			break;
		}
	} while (opcio!=3);
}

