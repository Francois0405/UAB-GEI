#include "FuncionsMasterMind.h"
#include <time.h>
using namespace std;

#define LongCodi 4
#define MaxIntents 15

//Escriure a partir d'aqui les funcions demanades NO posar main()
void Ajuda()
{
	cout << endl;
	cout << "L'objectiu del joc es trobar el codi ocult" << endl;
	cout << "El codi es de longitud " << LongCodi << " nombres del 0 al 9" << endl;
	cout << "Despres de cada intent et dona la seguent informacio: " << endl;
	cout << "	Nombre de nombres encertats (en la posicio correcte)" << endl;
	cout << "	Nombre de nombres aproximas (correctes pero mal col.locats)" << endl;
	cout << "El nombre de intents son " << MaxIntents << endl;
	cout << endl;
}

int Aleatori(int min, int max) //Genera la eleccio del ordinador (1,2,3)
{
	int random = rand() % (max - min + 1) + min;
	return random;
}

void GenerarCodiOcult(int CodiMaster[], int Dim)
{
	int i;
	for (i = 0;i < Dim;i++)
	{
		CodiMaster[i] = Aleatori(0, 9);
	}
}

int LlegirNombre(int min, int max)
{
	int valor = 0;
	if (min < max)
	{
		cout << "Entra valor entre " << min << " i " << max << ": " << endl;
		cin >> valor;
		while ((valor > max) || (valor < min))
		{
			cout << "Error: valor fora de l'interval" << endl;
			cin >> valor;
		}
	}
	return valor;
}

void IntToArray(int Nombre, int Codi[], int Dim)
{
	int i, res;

	for (i = 0;i < Dim;i++)
	{
		res = pow(10, (Dim - 1 - i));
		Codi[i] = Nombre / res % 10;
	}
}

void InicialitzarArray(int Array[], int Dim, int Valor)
{
	for (int i = 0; i < Dim; i++)
	{
		Array[i] = Valor;
	}
}

void FrequenciaDigit(int Codi[], int Dim, int Frequencia[])
{
	for (int i = 0;i < Dim;i++)
	{
		Frequencia[Codi[i]]++;

		// Sumem 1 perque hi ha un nou element

	}

	//for (int i = 0; i < 9; i++)
	//{
	//	cout << Frequencia[i] << " ";
	//}
	//cout << endl;
}

int NombreEncerts(int CodiMaster[], int CodiBreaker[], int Dim)
{
	int correcte = 0, i;

	for (i = 0;i < Dim;i++)
	{
		if (CodiMaster[i] == CodiBreaker[i])
		{
			correcte++;
		}
	}

	return correcte;
}

int Minim(int Valor1, int Valor2)
{
	int min = 0;
	if (Valor1 < Valor2)
	{
		min = Valor1;
	}
	else if (Valor1 > Valor2)
	{
		min = Valor2;
	}
	else min = Valor1;
	return min;
}

int NombreAproximacions(int FrequenciaCodiMaster[], int FrequenciaCodiBreaker[], int Encerts)
{
	int w = 0, i;

	for (i = 0;i < 9;i++)
	{
		w = w + Minim(FrequenciaCodiMaster[i], FrequenciaCodiBreaker[i]);
	}
	w = w - Encerts;
	return w;
}

void ImprimirComparacions(int Encerts, int Aproximacions)
{
	cout << "Aquest codi te " << Encerts << " Encerts i " << Aproximacions << " Aproximacions" << endl;
}

int JocMasterMind()
{
	int CodiMaster[LongCodi], CodiBreaker[LongCodi];
	int IntCodiBreaker, Encerts = 0, Aproximacions, Intents = 0;
	int FrequenciaCodiMaster[10], FrequenciaCodiBreaker[10];

	// Genera el Codi ocult.
	GenerarCodiOcult(CodiMaster, LongCodi);

	// Inicialitzar l'array de frequencia de codi master a 0.
	InicialitzarArray(FrequenciaCodiMaster, 10, 0);

	// Posa la quantitat de cada digit en la frenquencia.
	FrequenciaDigit(CodiMaster, 10, FrequenciaCodiMaster);

	// Mentres que no s'hagi guanyat o perdut, continua
	while ((Encerts < LongCodi) && (Intents < MaxIntents))
	{
		// Llegeix el codi de 0 a 10 ¿?
		IntCodiBreaker = LlegirNombre(0, 9999);

		// Coge el numero en int (4215) y lo pasa a array {4,2,1,5} por ejemplo
		IntToArray(IntCodiBreaker, CodiBreaker, LongCodi);

		// Inicialitza l'array de frequencia de codi breaker a 0.
		InicialitzarArray(FrequenciaCodiBreaker, 10, 0);

		// Posa la quantitat de cada digit en la frequencia
		FrequenciaDigit(CodiBreaker, LongCodi, FrequenciaCodiBreaker);

		// Cuenta el numero de enciertos
		Encerts = NombreEncerts(CodiMaster, CodiBreaker, LongCodi);

		// Cuenta el numero de aproximaciones
		Aproximacions = NombreAproximacions(FrequenciaCodiMaster, FrequenciaCodiBreaker, Encerts);;

		// Imprime el numero de aproximaciones y de Enciertos
		ImprimirComparacions(Encerts, Aproximacions);

		Intents++;
	}
	if (Intents >= MaxIntents)
	{
		return 0;
	}
	else
	{
		return Intents;
	}
}

void Menu()
{
	cout << "MASTER MIND" << endl << endl;
	cout << "Escull una opcio:" << endl << endl;
	cout << "Opcio 1 Ajuda" << endl;
	cout << "Opcio 2 Jugar" << endl;
	cout << "Opcio 3 Sortir" << endl;
}

void ImprimirResultatsJoc(int Intents)
{
	if (Intents == 0)
	{
		cout << "No has aconseguit descobrir el codi" << endl;
	}
	else
	{
		cout << "Has aconseguit descobrir el codi en " << Intents << " intents" << endl;
	}
}