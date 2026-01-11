#include "Tree.hpp"
#include <string>


int main()
{
	float grade = 0.0;
	bool valid = true;

	cout << endl << endl;
	cout << "Comment :=>>            Iniciant test dels exercicis sessio 17                " << endl;
	cout << "Comment :=>> ==================================================================" << endl;
	cout << "Comment :=>> ==================================================================" << endl;

	cout << "=======================" << endl;
	cout << "IMPRIMINT ARBRE ORDENAT" << endl;
	cout << "=======================" << endl;
	Tree<int> tOrd("arbreOrdenat.txt");
	cout << tOrd;




	//Valor existeix 
	cout << "Cercant valor existent: 92" << endl;
	cout << "Comment :=>> Resultat esperat: TRUE " << endl;
	Tree<int>* tsol1 = nullptr;
	if (tOrd.cerca(92, tsol1))
	{
		cout << "Comment :=>> CORRECTE" << endl;
		grade += 2.5;
		cout << "OK Valor 92 trobat" << endl;
	}
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		cout << "ERROR Valor 92 NO trobat" << endl;
		valid = false;
	}

	cout << "Comment :=>> " << endl << "Grade :=>> " << grade << endl;
	system("PAUSE");

	//Valor NO existeix 
	cout << "Cercant valor NO existent: 106" << endl;
	Tree<int>* tsol2 = nullptr;
	if (!tOrd.cerca(106, tsol2))
	{
		cout << "Comment :=>> CORRECTE" << endl;
		grade += 2.5;
		cout << "OK Valor 106 NO trobat" << endl;
	}
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		cout << "ERROR Valor 106 trobat??" << endl;
		valid = false;
	}

	cout << "Comment :=>> " << endl << "Grade :=>> " << grade << endl;
	system("PAUSE");

	cout << "==========================" << endl;
	cout << "IMPRIMINT ARBRE OPERACIONS" << endl;
	cout << "==========================" << endl;

	Tree<string> tOp("arbreOps.txt");
	cout << tOp;

	cout << "MOSTRA EXPRESSIO Recursiva" << endl;
	std::string sEstudiant = "";
	std::string sep = " ";
	std::string sSolucio = "3" + sep + "+" + sep + "9" + sep + "*" + sep + "5" + sep + "/" + sep + "2" + sep + "+" + sep + "7" + sep;
	tOp.mostraExpressioRec(sEstudiant, sep);

	cout << "MOSTRA STRING RETORNAT PER EXPRESSIO Recursiva" << endl;
	if (sSolucio == sEstudiant)
	{
		cout << "Comment :=>> MOSTRA EXPRESSIO Recursiva CORRECTE" << endl;
		cout << "Comment :=>>" << sEstudiant << endl;
		grade += 1.0;
	}
	else
	{
		cout << "Comment :=>> MOSTRA EXPRESSIO Recursiva ERROR" << endl;
		cout << "Resultat incorrecte" << endl;
		cout << "Comment :=>>" << sEstudiant << endl;
		valid = false;
	}

	cout << "Comment :=>> " << endl << "Grade :=>> " << grade << endl;
	system("PAUSE");

	sEstudiant = "";
	cout << "MOSTRA EXPRESSIO ITER" << endl;
	tOp.mostraExpressioIter(sEstudiant, sep);

	cout << "MOSTRA STRING RETORNAT PER EXPRESSIO Iterativa" << endl;
	if (sSolucio == sEstudiant)
	{
		cout << "Comment :=>> MOSTRA EXPRESSIO Iterativa CORRECTE" << endl;
		cout << "Comment :=>>" << sEstudiant << endl;
		grade += 1.0;
	}
	else
	{
		cout << "Comment :=>> MOSTRA EXPRESSIO Iterativa ERROR" << endl;
		cout << "Resultat incorrecte" << endl;
		cout << "Comment :=>>" << sEstudiant << endl;
		valid = false;
	}

	cout << "Comment :=>> " << endl << "Grade :=>> " << grade << endl;
	system("PAUSE");

	cout << "AVALUANT EXPRESSIO" << endl;
	float solucio;
	solucio = tOp.avalua();

	if (solucio == 37)
	{
		cout << "Comment :=>> CORRECTE" << endl;
		grade += 3.0;
		cout << "OK Resultat es 37" << endl;
	}
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		cout << "Resultat incorrecte" << endl;
		valid = false;
	}


	cout << endl;

	cout << "Comment :=>> =====================================================================" << endl;
	if (valid)
		cout << "Comment :=>> Final del test sense errors" << endl;

	cout << "Comment :=>> " << endl << "Grade :=>> " << grade << endl;

	system("pause");

	return 0;
}