#include "Operacions.h"
#include "Recta.h"
#include <iostream>

using namespace std;

void mostraBool(bool logic)
{
	if (logic)
		cout << "TRUE";
	else
		cout << "FALSE";
}

float testFormaCanonica()
{
	float reduccio = 0.0;
	const int N_PROVES = 4;

	float rOriginal[N_PROVES][3] =
	{
		{1, 1, 0},
		{0, 2, 2},
		{2, 0, 2},
		{2, 4, 2}
	};

	float rResultat[N_PROVES][3] =
	{
		{ 1, 1, 0 },
		{ 0, -1, -1 },
		{ -1, 0, -1 },
		{ -1, -2, -1 }
	};

	cout << endl;
	cout << "Comment :=>> Iniciant test funcio formaCanonica" << endl;
	cout << "Comment :=>> ==================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Inicialitzant recta amb valors: " << rOriginal[i][0] << ", " << rOriginal[i][1] << ", " << rOriginal[i][2] << endl;
		Recta r(rOriginal[i][0], rOriginal[i][1], rOriginal[i][2]);
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Resultat esperat de la forma canonica: " << "a = " << rResultat[i][0] << ", b = " << rResultat[i][1] << ", c = " << rResultat[i][2] << endl;
		r.formaCanonica();
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Resultat obtingut de la forma canonica: " << "a = " << r.getA() << ", b = " << r.getB() << ", c = " << r.getC() << endl;
		if ((r.getA() == rResultat[i][0]) && (r.getB() == rResultat[i][1]) && (r.getC() == rResultat[i][2]))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
		cout << "Comment :=>> ------------------------------------------" << endl;
	}
	return reduccio;
}


float testConstructorPunts()
{
	float reduccio = 0.0;
	const int N_PROVES = 4;

	Punt punts[N_PROVES][2] =
	{
		{{ 0, 1},{2, 1}},
		{{ 2, 0},{2, -2}},
		{{ 1, 2},{2, 4}},
		{{-1, 2},{1, 0}}
	};

	Recta rResultat[N_PROVES] =
	{
		{ 0, 1, -1},
		{ 0.5, 0, -1 },
		{ 2, -1, 0 },
		{ 1, 1, -1 }
	};

	cout << endl;
	cout << "Comment :=>> Iniciant test constructor a partir de dos punts" << endl;
	cout << "Comment :=>> ===============================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Inicialitzant recta a partir dels punts: (" << punts[i][0].getX() << ", " << punts[i][0].getY() << "), (" <<
			punts[i][1].getX() << ", " << punts[i][1].getY() << ")" << endl;
		Recta r(punts[i][0], punts[i][1]);
		cout << "Comment :=>> Convertint recta a forma canonica... " << endl;
		r.formaCanonica();
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Resultat esperat: " << "a = " << rResultat[i].getA() << ", b = " << rResultat[i].getB() << ", c = " << rResultat[i].getC() << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Resultat obtingut: " << "a = " << r.getA() << ", b = " << r.getB() << ", c = " << r.getC() << endl;
		if ((r.getA() == rResultat[i].getA()) && (r.getB() == rResultat[i].getB()) && (r.getC() == rResultat[i].getC()))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
		cout << "Comment :=>> ------------------------------------------" << endl;
	}
	return reduccio;
}

float testIgualsParalels()
{
	float reduccio = 0.0;
	const int N_PROVES = 6;

	Recta recta1[N_PROVES] =
	{
		{ 0, 1, 1 },{ 0, 1, 1 },{ 1, 0, 1 },{ 1, 0, 1 } , {1, 1, 1},{ 1, 1, 1 }
	};

	Recta recta2[N_PROVES] =
	{
		{ 0, 2, 2 },{ 0, 2, 1 },{ 1, 1, 1 }, {3, 0, 1}, {2, 2, 2}, {2, 1, 2}
	};

	bool resultatIguals[N_PROVES] = { true, false, false, false, true, false };
	bool resultatParaleles[N_PROVES] = { true, true, false, true, true, false };

	cout << endl;
	cout << "Comment :=>> Iniciant test comprovacio rectes iguals i paral.leles" << endl;
	cout << "Comment :=>> =====================================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Recta 1: a = " << recta1[i].getA() << ", b = " << recta1[i].getB() << ", c = " << recta1[i].getC() << endl;
		cout << "Comment :=>> Recta 2: a = " << recta2[i].getA() << ", b = " << recta2[i].getB() << ", c = " << recta2[i].getC() << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Resultat esperat operador ==: "; mostraBool(resultatIguals[i]); cout << endl;
		cout << "Comment :=>> Resultat comprovacio rectes paral.leles: "; mostraBool(resultatParaleles[i]); cout << endl;
		cout << "Comment :=>> ---" << endl;
		bool iguals = (recta1[i] == recta2[i]);
		bool paraleles = recta1[i].paralela(recta2[i]);
		cout << "Comment :=>> Resultat obtingut operador ==: ";  mostraBool(iguals); cout << endl;
		cout << "Comment :=>> Resultat obtingut comprovacio rectes paral.leles: "; mostraBool(paraleles); cout << endl;
		if ((iguals == resultatIguals[i]) && (paraleles == resultatParaleles[i]))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
		cout << "Comment :=>> ------------------------------------------" << endl;
	}
	return reduccio;
}


float testDistancies()
{
	float reduccio = 0.0;
	const int N_PROVES = 6;

	Recta recta[N_PROVES] =
	{
		{ 0, 1, 1 },{ 0, 1, 1 },{ 1, 0, 1 },{ 3, 4, -5 } ,{ -3, -4, 5 },{ 4, 3, -5 }
	};

	Punt punt[N_PROVES] =
	{
		{ 0, 0 },{ 1, -1 },{ 0, 0},{ 5, 5 },{ 5, -5 },{ 5, -5 }
	};

	float distanciaResultat[N_PROVES] = { 1, 0, 1, 6, 2, 0 };

	cout << endl;
	cout << "Comment :=>> Iniciant test comprovacio distancia punt a recta" << endl;
	cout << "Comment :=>> ================================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Recta: a = " << recta[i].getA() << ", b = " << recta[i].getB() << ", c = " << recta[i].getC() << endl;
		cout << "Comment :=>> Punt: (" << punt[i].getX() << ", " << punt[i].getY() << ")" << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Resultat esperat distancia: " << distanciaResultat[i] << endl;
		cout << "Comment :=>> ---" << endl;
		float distancia = recta[i] - punt[i];
		cout << "Comment :=>> Resultat obtingut distancia: " << distancia << endl;
		if (distancia == distanciaResultat[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
		cout << "Comment :=>> ------------------------------------------" << endl;
	}
	return reduccio;
}

int main()
{
	float grade = 0;
	float reduccio;


	cout << endl << "Grade :=>> " << grade << endl << endl;

	reduccio = testFormaCanonica();
	if (reduccio > 3.0)
		reduccio = 3.0;
	grade += (2.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	reduccio = testConstructorPunts();
	if (reduccio > 3.0)
		reduccio = 3.0;
	grade += (2.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	reduccio = testIgualsParalels();
	if (reduccio > 5.0)
		reduccio = 5.0;
	grade += (3.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	reduccio = testDistancies();
	if (reduccio > 5.0)
		reduccio = 5.0;
	grade += (3.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	if (grade < 0)
		grade = 0.0;
	cout << "Comment :=>> ------------------------------------------" << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}