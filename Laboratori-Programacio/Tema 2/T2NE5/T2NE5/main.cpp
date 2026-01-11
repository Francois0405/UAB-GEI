#include "LlistaPolimorfisme.h"
#include "Producte.h"
#include "Llibre.h"
#include "Electrodomestic.h"
#include <iostream>
using namespace std;

void mostraBool(bool logic)
{
	if (logic)
		cout << "TRUE";
	else
		cout << "FALSE";
}

void afegeixProductes(LlistaPolimorfisme<Producte>& lp)
{
	const int MAX_PROVES = 6;
	int tipusProducte[MAX_PROVES] = { 0, 1, 0, 0, 1, 0 };
	string codiProducte[MAX_PROVES] = { "CODI_1", "CODI_2" , "CODI_3" , "CODI_4" , "CODI_5" , "CODI_6" };
	int preuProducte[MAX_PROVES] = { 10, 200, 30, 40, 500, 60 };
	string titolLlibre[MAX_PROVES] = { "TITOL_1", "", "TITOL_3", "TITOL_4", "", "TITOL_6" };
	string autorLlibre[MAX_PROVES] = { "AUTOR_1", "", "AUTOR_3", "AUTOR_4", "", "AUTOR_6" };
	int nPagines[MAX_PROVES] = { 100, 0, 300, 400, 0, 600 };
	string marca[MAX_PROVES] = { "", "MARCA_2", "", "", "MARCA_5", "" };
	string model[MAX_PROVES] = { "", "MODEL_2", "", "", "MODEL_5", "" };
	float volum[MAX_PROVES] = { 0, 20, 0, 0, 50, 0 };

	for (int i = 0; i < MAX_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> Afegint producte " << i + 1 << endl;
		if (tipusProducte[i] == 0)
		{
			cout << "Comment :=>> LLIBRE" << endl;
			cout << "Comment :=>> Codi: " << codiProducte[i] << endl;
			cout << "Comment :=>> Preu: " << preuProducte[i] << endl;
			cout << "Comment :=>> Titol: " << titolLlibre[i] << endl;
			cout << "Comment :=>> Autor: " << autorLlibre[i] << endl;
			cout << "Comment :=>> N. pagines: " << nPagines[i] << endl;
			Llibre l(codiProducte[i], preuProducte[i], titolLlibre[i], autorLlibre[i], nPagines[i]);
			lp.afegeixElement(l);
		}
		else
		{
			cout << "Comment :=>> ELECTRODOMESTIC" << endl;
			cout << "Comment :=>> Codi: " << codiProducte[i] << endl;
			cout << "Comment :=>> Preu: " << preuProducte[i] << endl;
			cout << "Comment :=>> Marca: " << marca[i] << endl;
			cout << "Comment :=>> Model: " << model[i] << endl;
			cout << "Comment :=>> Volum: " << volum[i] << endl;
			Electrodomestic e(codiProducte[i], preuProducte[i], marca[i], model[i], volum[i]);
			lp.afegeixElement(e);
		}
	}

}

float testEliminaElement(LlistaPolimorfisme<Producte>& lp)
{
	const int MAX_PROVES = 3;
	string codiProducte[MAX_PROVES] = { "CODI_2", "CODI_3", "CODI_7" };
	bool resultatEsperat[MAX_PROVES] = { true, true, false };

	float reduccio = 0.0;

	cout << endl;
	cout << "Comment :=>> Iniciant test metode ELIMINA ELEMENT" << endl;
	cout << "Comment :=>> (Suposa funcionament correcte de afegeixElement)" << endl;
	cout << "Comment :=>> ================================================" << endl;

	for (int i = 0; i < MAX_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST ELIMINA ELEMENT " << i + 1 << endl;
		cout << "Comment :=>> Codi Producte: " << codiProducte[i] << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Resultat esperat: "; mostraBool(resultatEsperat[i]); cout << endl;
		bool resultat = lp.eliminaElement(codiProducte[i]);
		cout << "Comment :=>> Resultat obtingut: "; mostraBool(resultat); cout << endl;
		if (resultat == resultatEsperat[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}
	return reduccio;
}



float testRecuperaElement(LlistaPolimorfisme<Producte>& lp)
{
	const int MAX_PROVES = 3;
	int tipusProducte[MAX_PROVES] = { 0, 1, -1 };
	string codiProducte[MAX_PROVES] = { "CODI_1", "CODI_5" , "CODI_2" };
	bool resultatEsperat[MAX_PROVES] = { true, true, false };
	int preuProducte[MAX_PROVES] = { 30, 500, 0 };
	string titolLlibre[MAX_PROVES] = { "TITOL_1", "", "" };
	string autorLlibre[MAX_PROVES] = { "AUTOR_1", "", "" };
	int nPagines[MAX_PROVES] = { 100, 0, 0 };
	string marca[MAX_PROVES] = { "", "MARCA_5", "" };
	string model[MAX_PROVES] = { "", "MODEL_5", "" };
	float volum[MAX_PROVES] = { 0, 50, 0 };

	float reduccio = 0.0;

	cout << endl;
	cout << "Comment :=>> Iniciant test metode RECUPERA ELEMENT" << endl;
	cout << "Comment :=>> (Suposa funcionament correcte afegeixElement i eliminaElement)" << endl;
	cout << "Comment :=>> ==============================================================" << endl;

	for (int i = 0; i < MAX_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST RECUPERA ELEMENT " << i + 1 << endl;
		cout << "Comment :=>> Codi Producte: " << codiProducte[i] << endl;
		cout << "Comment :=>> Resultat esperat: "; mostraBool(resultatEsperat[i]); cout << endl;
		if (tipusProducte[i] == 0)
		{
			cout << "Comment :=>> Titol esperat: " << titolLlibre[i] << endl;
			cout << "Comment :=>> Autor esperat: " << autorLlibre[i] << endl;
			cout << "Comment :=>> N. pagines esperat: " << nPagines[i] << endl;


			Producte* p;
			bool resultat = lp.getElement(codiProducte[i], p);
			Llibre* l = (Llibre*)p;
			cout << "Comment :=>> ------" << endl;
			cout << "Comment :=>> Resultat obtingut: "; mostraBool(resultat); cout << endl;
			if (resultat)
			{
				cout << "Comment :=>> Titol obtingut: " << l->getTitol() << endl;
				cout << "Comment :=>> Autor obtingut: " << l->getAutor() << endl;
				cout << "Comment :=>> N. pagines obtingut: " << l->getNPagines() << endl;
			}
			if (resultat == resultatEsperat[i])
			{
				if ((titolLlibre[i] == l->getTitol()) && (autorLlibre[i] == l->getAutor()) && (nPagines[i] == l->getNPagines()))
					cout << "Comment :=>> CORRECTE" << endl;
				else
				{
					cout << "Comment :=>> ERROR" << endl;
					reduccio += 1.0;
				}
			}
			else
			{
				cout << "Comment :=>> ERROR" << endl;
				reduccio += 1.0;
			}
		}
		else
			if (tipusProducte[i] == 1)
			{
				cout << "Comment :=>> Marca esperada: " << marca[i] << endl;
				cout << "Comment :=>> Model esperat: " << model[i] << endl;
				cout << "Comment :=>> Volum esperat: " << volum[i] << endl;

				Producte* p;
				bool resultat = lp.getElement(codiProducte[i], p);
				Electrodomestic* e = (Electrodomestic*)p;
				cout << "Comment :=>> ------" << endl;;
				cout << "Comment :=>> Resultat obtingut: "; mostraBool(resultat); cout << endl;
				if (resultat)
				{
					cout << "Comment :=>> Titol obtingut: " << e->getMarca() << endl;
					cout << "Comment :=>> Autor obtingut: " << e->getModel() << endl;
					cout << "Comment :=>> N. pagines obtingut: " << e->getVolum() << endl;
				}
				if (resultat == resultatEsperat[i])
				{
					if ((marca[i] == e->getMarca()) && (model[i] == e->getModel()) && (volum[i] == e->getVolum()))
						cout << "Comment :=>> CORRECTE" << endl;
					else
					{
						cout << "Comment :=>> ERROR" << endl;
						reduccio += 1.0;
					}
				}
				else
				{
					cout << "Comment :=>> ERROR" << endl;
					reduccio += 1.0;
				}
			}
			else
			{
				Producte* p;
				bool resultat = lp.getElement(codiProducte[i], p);
				cout << "Comment :=>> ------" << endl;
				cout << "Comment :=>> Resultat obtingut: "; mostraBool(resultat); cout << endl;
				if (resultat == resultatEsperat[i])
				{
					cout << "Comment :=>> CORRECTE" << endl;
				}
				else
				{
					cout << "Comment :=>> ERROR" << endl;
					reduccio += 1.0;
				}
			}
	}
	return reduccio;
}

float testConstructorCopia(LlistaPolimorfisme<Producte>& lp)
{
	float reduccio = 0.0;
	const int MAX_PROVES = 4;
	int tipusProducte[MAX_PROVES] = { 1, 0, 1, 0 };
	string codiProducte[MAX_PROVES] = { "CODI_1" , "CODI_4" , "CODI_5" , "CODI_6" };

	LlistaPolimorfisme<Producte> lpCopia(lp);
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> Fent copia de LlistaPolimorfisme amb constructor de copia....." << endl;
	if (true)
	{
		LlistaPolimorfisme<Producte> lpCopiaAux(lpCopia);
	}
	cout << "Comment :=>> Comparant copia amb original....." << endl;

	bool correcte = true;

	int i = 0;
	while (correcte && (i < MAX_PROVES))
	{
		if (tipusProducte == 0)
		{
			Producte* p, * pCopia;
			Llibre* l, * lCopia;
			correcte = lpCopia.getElement(codiProducte[i], pCopia);
			lp.getElement(codiProducte[i], p);
			l = (Llibre*)p;
			lCopia = (Llibre*)pCopia;
			if (correcte)
			{
				if ((l->getTitol() == lCopia->getTitol()) && (l->getAutor() == lCopia->getAutor()) && (l->getNPagines() == lCopia->getNPagines()))
					i++;
				else
					correcte = false;
			}
		}
		else
		{
			Producte* p, * pCopia;
			Electrodomestic* e, * eCopia;
			correcte = lpCopia.getElement(codiProducte[i], pCopia);
			lp.getElement(codiProducte[i], p);
			e = (Electrodomestic*)p;
			eCopia = (Electrodomestic*)pCopia;
			if (correcte)
			{
				if ((e->getMarca() == eCopia->getMarca()) && (e->getModel() == eCopia->getModel()) && (e->getVolum() == eCopia->getVolum()))
					i++;
				else
					correcte = false;
			}
		}
	}
	if (!correcte)
	{
		reduccio = 5.0;
		cout << "Comment :=>> ERROR" << endl;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;
	return reduccio;
}

float testOperadorAssignacio(LlistaPolimorfisme<Producte>& lp)
{
	float reduccio = 0.0;
	const int MAX_PROVES = 4;
	int tipusProducte[MAX_PROVES] = { 1, 0, 1, 0 };
	string codiProducte[MAX_PROVES] = { "CODI_1" , "CODI_4" , "CODI_5" , "CODI_6" };

	LlistaPolimorfisme<Producte> lpCopia;
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> Fent copia de LlistaPolimorfisme amb operador assignacio....." << endl;
	if (true)
	{
		LlistaPolimorfisme<Producte> lpCopiaAux;
		lpCopiaAux = lp;
		lpCopia = lpCopiaAux;
	}
	cout << "Comment :=>> Comparant copia amb original....." << endl;

	bool correcte = true;

	int i = 0;
	while (correcte && (i < MAX_PROVES))
	{
		if (tipusProducte == 0)
		{
			Producte* p, * pCopia;
			Llibre* l, * lCopia;
			correcte = lpCopia.getElement(codiProducte[i], pCopia);
			lp.getElement(codiProducte[i], p);
			l = (Llibre*)p;
			lCopia = (Llibre*)pCopia;
			if (correcte)
			{
				if ((l->getTitol() == lCopia->getTitol()) && (l->getAutor() == lCopia->getAutor()) && (l->getNPagines() == lCopia->getNPagines()))
					i++;
				else
					correcte = false;
			}
		}
		else
		{
			Producte* p, * pCopia;
			Electrodomestic* e, * eCopia;
			correcte = lpCopia.getElement(codiProducte[i], pCopia);
			lp.getElement(codiProducte[i], p);
			e = (Electrodomestic*)p;
			eCopia = (Electrodomestic*)pCopia;
			if (correcte)
			{
				if ((e->getMarca() == eCopia->getMarca()) && (e->getModel() == eCopia->getModel()) && (e->getVolum() == eCopia->getVolum()))
					i++;
				else
					correcte = false;
			}
		}
	}
	if (!correcte)
	{
		reduccio = 5.0;
		cout << "Comment :=>> ERROR" << endl;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;
	return reduccio;
}

int main()
{
	float grade = 0.0;
	float reduccio;

	LlistaPolimorfisme<Producte> lp;

	cout << endl;
	cout << "Comment :=>> Iniciant test " << endl;
	cout << "Comment :=>> ==============" << endl;

	cout << endl << "Grade :=>> " << grade << endl << endl;

	cout << endl;
	cout << "Comment :=>> Afegint productes per inicialitzar la llista..........." << endl;
	cout << "Comment :=>> =======================================================" << endl;
	afegeixProductes(lp);


	reduccio = testEliminaElement(lp);
	if (reduccio > 4.0)
		reduccio = 4.0;
	grade += (3.0 - reduccio);

	cout << "Grade :=>> " << grade << endl;

	reduccio = testRecuperaElement(lp);
	if (reduccio > 4.0)
		reduccio = 4.0;
	grade += (3.0 - reduccio);

	cout << "Grade :=>> " << grade << endl;

	reduccio = testConstructorCopia(lp);
	if (reduccio > 3.0)
		reduccio = 3.0;
	grade += (2.0 - reduccio);

	cout << "Grade :=>> " << grade << endl;

	reduccio = testOperadorAssignacio(lp);
	if (reduccio > 3.0)
		reduccio = 3.0;
	grade += (2.0 - reduccio);



	if (grade < 0)
		grade = 0.0;
	cout << "Comment :=>> ------------------------------------------" << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;
	return 0;

}