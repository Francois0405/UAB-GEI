//Main exercici 19
# pragma once
#include "Heap.hpp"
#include <string>
#include <vector>
#include <algorithm>

bool IgualFitxers(string nomF1, string nomF2)
{
	ifstream f1, f2;
	f1.open(nomF1);
	f2.open(nomF2);
	bool iguals = true;

	if (f1.is_open() && f2.is_open())
	{
		int cont = 0, linia = 0;
		while (!f1.eof() && !f2.eof())
		{
			++linia;
			string a, b;
			getline(f1, a);
			size_t pos;
			if ((pos = a.find_first_of(char(13))) < string::npos)
				a = a.substr(0, pos);
			getline(f2, b);
			if ((pos = b.find_first_of(char(13))) < string::npos)
				b = b.substr(0, pos);
			if (a != b)
			{
				++cont;
				iguals = false;
			}
		}
		if (!f1.eof() && f2.eof())
		{
			cout << "Comment :=>> ==== Fitxer : " << nomF2 << " es mes curt que " << nomF1 << endl;
		}
		if (!f2.eof() && f1.eof())
		{
			cout << "Comment :=>> ==== Fitxer : " << nomF1 << " es mes curt que " << nomF2 << endl;
		}
	}
	else
	{
		throw "Error al fitxer de sortida al comparar.";
	}
	return iguals;
}

int main()
{
	float grade = 0.0;
	bool valid = true;



	//Proves de Heaps
	Heap<int> mont;

	cout << "Comment :=>>==============================" << endl;
	cout << "Comment :=>>=======LLEGINT HEAP===========" << endl;
	cout << "Comment :=>>==============================" << endl;
	mont.read("heap.txt");

	cout << "Comment :=>>==============================" << endl;
	cout << "Comment :=>>=======ESCRIU HEAP============" << endl;
	cout << "Comment :=>>==============================" << endl;

	cout << mont;

	ofstream student_file;
	student_file.open("sortida_escriu_heap.txt");
	student_file << mont;
	student_file.close();


	if (IgualFitxers("sortida_escriu_heap.txt", "sortida_escriu_heap_esperada.txt"))
	{
		cout << "Comment :=>> CORRECTE" << endl;

	}
	else
	{
		cout << "Comment :=>> NO ES CORRECTE" << endl;
		valid = false;
	}

	cout << "Comment :=>>=================================" << endl;
	cout << "Comment :=>>=======INSERIM 12  Ex1     ======" << endl;
	cout << "Comment :=>>=================================" << endl;

	mont.insert(12);
	cout << mont;

	ofstream student_file1;
	student_file1.open("sortida_inserir12.txt");
	student_file1 << mont;
	student_file1.close();

	if (IgualFitxers("sortida_inserir12.txt", "sortida_inserir12_esperada.txt"))
	{
		cout << "Comment :=>> CORRECTE" << endl;
		grade += 2.5;
	}
	else
	{
		cout << "Comment :=>> NO ES CORRECTE" << endl;
		valid = false;
	}

	cout << "Comment :=>>=================================" << endl;
	cout << "Comment :=>>=======ESBORREM MIN  Ex2   ======" << endl;
	cout << "Comment :=>>=================================" << endl;

	mont.delMin();
	cout << mont;

	ofstream student_file2;
	student_file2.open("sortida_esborrarmin.txt");
	student_file2 << mont;
	student_file2.close();

	if (IgualFitxers("sortida_esborrarmin.txt", "sortida_esborrarmin_esperada.txt"))
	{
		cout << "Comment :=>> CORRECTE" << endl;
		grade += 2.5;
	}
	else
	{
		cout << "Comment :=>> NO ES CORRECTE" << endl;
		valid = false;
	}



	cout << "Comment :=>>=======================================" << endl;
	cout << "Comment :=>>=======FER HEAPIFY VECTOR  Ex3   ======" << endl;
	cout << "Comment :=>>=======================================" << endl;

	std::vector<int> v = { 45,89,23,1,4,7,8,2,15,79 };

	Heap<int> mont3(v);

	cout << "Comment :=>>=======VECTOR ORIGINAL=====" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ; ";
	}

	cout << endl;

	cout << "Comment :=>>=======VECTOR Heapify=====" << endl;
	cout << mont3;

	ofstream student_file3;
	student_file3.open("sortida_vectorHeapify.txt");
	student_file3 << mont;
	student_file3.close();

	if (IgualFitxers("sortida_vectorHeapify.txt", "sortida_vectorHeapify_esperada.txt"))
	{
		cout << "Comment :=>> CORRECTE" << endl;
		grade += 2.5;
	}
	else
	{
		cout << "Comment :=>> NO ES CORRECTE" << endl;
		valid = false;
	}

	cout << "Comment :=>>=======================================" << endl;
	cout << "Comment :=>>=======ORDENA VECTOR  Ex4   ======" << endl;
	cout << "Comment :=>>=======================================" << endl;

	v = mont3.ordenar();



	cout << "=======VECTOR DESPRES ORDRE=====" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ; ";
	}
	cout << endl;

	ofstream student_file4;
	student_file4.open("ordenarvector.txt");
	for (int i = 0; i < v.size(); i++)
	{
		student_file4 << v[i] << " ; ";
	}
	student_file4 << endl;

	student_file4.close();

	if (IgualFitxers("ordenarvector.txt", "ordenarvector_esperada.txt"))
	{
		cout << "Comment :=>> CORRECTE" << endl;
		grade += 2.5;
	}
	else
	{
		cout << "Comment :=>> NO ES CORRECTE" << endl;
		valid = false;
	}


	cout << "Comment :=>>=======================================" << endl;
	cout << "Comment :=>>=======CREA VECTOR         ============" << endl;
	cout << "Comment :=>>=======================================" << endl;

	std::vector<int> vh = { 45,89,23,1,4,7,8,2,15,79 };
	for (size_t i = 0; i < vh.size(); i++)
		cout << vh[i] << endl;

	cout << "Comment :=>>========================================" << endl;
	cout << "Comment :=>>=======HEAPYFICA VECTOR STD ============" << endl;
	cout << "Comment :=>>========================================" << endl;

	std::make_heap(vh.begin(), vh.end(), std::greater <> { });

	cout << "Comment :=>>================================================" << endl;
	cout << "Comment :=>>=======ESCRIU VECTOR HEAPIFICAT STD ============" << endl;
	cout << "Comment :=>>================================================" << endl;

	for (size_t i = 0; i < vh.size(); i++)
		cout << vh[i] << endl;

	cout << "Comment :=>> =====================================================================" << endl;
	if (valid)
		cout << "Comment :=>> Final del test sense errors" << endl;

	cout << "Comment :=>> " << endl << "Grade :=>> " << grade << endl;


	return 0;
}

