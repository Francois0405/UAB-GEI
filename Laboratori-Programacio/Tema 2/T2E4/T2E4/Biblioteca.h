#pragma once
#include "Data.h"
#include "Publicacio.h"
#include "Prestec.h"
#include <vector>
#include <string>
using namespace std;

class Biblioteca
{
public:
	Biblioteca() {}
	~Biblioteca() {
		for (auto p : m_publicacions)
			delete p;
	}

	void llegirPublicacions(const string& nomFitxer);
	bool prestar(const string& idUsuari, const string& codi, const Data& dataPrestec, Data& dataRetorn, int nExemplar = 0);
	bool retornar(const string& idUsuari, const string& codi, const Data& data, bool& dataCorrecta, int nExemplar = 0);

private:
	vector<Publicacio*> m_publicacions;
	vector<Prestec> m_prestecs;
};