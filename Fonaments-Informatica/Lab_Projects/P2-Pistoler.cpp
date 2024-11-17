#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define ESCUT 1
#define CARREGA 2
#define TRET 3

#define EMPAT 0
#define WINA 1
#define WINB 2

void PresentacioJoc()
{
	cout << "Dam dam dish, es un joc infantil on es simula un duel de pistolers. L'objectiu del joc es matar al contrincant" << endl;
	cout << "El joc es per parelles hi ha tres moviments basics :" << endl;
	cout << "- Bracos en creu sobre el pit : escut" << endl;
	cout << "- Mans en forma de pistola apuntant al contrincant : tret" << endl;
	cout << "- Dits index i del mig tocant el lateral del front : carregar" << endl;
	cout << "El joc es al millor de N partides on N es un nombre senar" << endl;
}

bool Senar(int num) // Diu si el numero es senar o no (true/false)
{
	if (num != 0)
	{
		int res;
		res = num % 2;
		if (res != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

int LlegirSenar () // Demana introduir y diu si es senar o no.
{
	int a;
	bool se = false;

	cout << "Introduir un nombre senar" << endl;
	cin >> a;
	se = Senar(a);

	while (se == false)
	{
		cout << "ERROR: El nombre introduit es parell" << endl;
		cin >> a;
		se = Senar(a);
	}
	return a;
}

int Aleatori(int min, int max) //Genera la eleccio del ordinador (1,2,3)
{
	srand((unsigned)time(NULL));
	int random = rand() % (max - min + 1) + min;
	return random;
}

void MenuDamDamDish()
{
	cout << "Escull entre:" << endl;
	cout << "1. Escut: protegeix dels trets del rival" << endl;
	cout << "2. Carrega: afegeix una bala al carregador" << endl;
	cout << "3. Tret: dispara al teu rival" << endl;
	//- ESCUT:		L’escut protegeix dels trets del rival.
	//- TRET:		Mata al rival.
	//- CARREGAR:	Carrega la pistola.
}

int LlegirNombre(int min, int max)
{
	int a;

	cout << "Entra valor entre " << min << " i " << max << ":";
	cin >> a;

	while (a<min || a>max)
	{
		cout << "Error: valor fora de l'interval" << endl;
		cin >> a;
	}
	return a;
}

void MissatgeAI(int opcio_ECT)
{
	cout << "L'ordinador ha escollit aleatoriament ";
	switch (opcio_ECT)
	{
	case 1: cout << "ESCUT" << endl;
		break;
	case 2: cout << "CARREGA" << endl;
		break;
	case 3: cout << "TRET" << endl;
		break;
	}
}

int JocDamDamDish(int jA, int jB)
{
	bool empat = true;
	bool protegitA = false, protegitB = false;

	if (jA == TRET && jB == CARREGA)
	{
		return WINA;
	}
	else
	if (jA == TRET && jB == CARREGA)
	{
		return WINB;
	}
	else return EMPAT;
}

int main()
{
	int elec_A, elec_B, min, max, num, se, res, balesA = 1, balesB = 1;
	int nombre_p, cont_winA = 0, cont_winB = 0, partides_per_guany;

	PresentacioJoc();
	nombre_p = LlegirSenar();
	partides_per_guany = (nombre_p / 2) + 1;
	do
	{
		if (balesB > 0) // Eleccio AI
		{
			elec_B = Aleatori(1, 3);
		}
		else
		{
			elec_B = Aleatori(1, 2);
		}
		MenuDamDamDish();

		elec_A = LlegirNombre(1, 3);
		if ((balesA == 0) && (elec_A == TRET))
		{
			cout << "No tens bales. Escull entre 1 (Escut) o 2 (Carrega)" << endl;
			elec_A = LlegirNombre(1, 2);
		}

		switch (elec_A)
		{
		case CARREGA:
			balesA++;
			break;
		case TRET:
			balesA--;
			break;
		default:
			break;
		}

		switch (elec_B)
		{
		case CARREGA:
			balesB++;
			break;
		case TRET: 
			balesB--;
			break;
		default:
			break;
		}
		
		res = JocDamDamDish(elec_A, elec_B); // empat 0 - winA 1 - winB 2
		MissatgeAI(elec_B);

		switch(res)
		{
		case EMPAT: cout << "Empat. Seguim la partida" << endl;
			break;

		case WINA: cout << "Guanyes Tu!!!";
			cont_winA++;
			cout << "MARCADOR - Ordinador " << cont_winB << " Tu " << cont_winA << endl;
			balesA = 1;
			balesB = 1;
			break;

		case WINB: cout << "Et guanya un ordinador!!!";
			cont_winB++;
			cout << "MARCADOR - Ordinador " << cont_winB << " Tu " << cont_winA << endl;
			balesA = 1;
			balesB = 1;
			break;
		}
	} while (cont_winA < partides_per_guany && cont_winB < partides_per_guany);

	if (cont_winA >= partides_per_guany)
	{
		cout << "Tu ets el guanyador final";
	}
	else 
	{
		cout << "El guanyador final es l'ordinador";
	}
}