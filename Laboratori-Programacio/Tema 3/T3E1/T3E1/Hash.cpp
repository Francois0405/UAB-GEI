#include "Hash.h"
#include <math.h>
using namespace std;

Hash::Hash()
{
	m_numOcupats = 0;
	m_maxElements = 15;
	m_descripcioDefecte = "Definicio no existent";
	m_diccionari.resize(m_maxElements, pair<string, string>("", ""));
	m_estat.resize(m_maxElements, LLIURE);
}

Hash::Hash(int sizeIni, const string& descripcioDefecte)
{
	m_maxElements = sizeIni;
	m_descripcioDefecte = descripcioDefecte;

	m_diccionari.resize(m_maxElements, pair<string, string>("", ""));
	m_estat.resize(m_maxElements, LLIURE);
	m_numOcupats = 0;
}

Hash::~Hash()
{
}

void Hash::insert(const string& clau, const string& descripcio)
{
	int indexi = codi(clau);
	int index = indexi;
	int vegades = 1;
	bool trobat = false;

	while ((m_estat[index] != LLIURE) && !trobat)
	{
		if ((m_estat[index] == OCUPAT) && (m_diccionari[index].first == clau))
		{
			trobat = true;
		}
		else
		{
			index = codi2(indexi, vegades);
			vegades++;
			if (vegades >= m_maxElements) break;
		}
	}

	if (trobat)
	{
		m_diccionari[index].second = descripcio;
	}
	else
	{
		insertIntern(clau, descripcio);
	}
}

bool Hash::find(const string& clau, string& definicio)
{
	int index = cerca(clau);

	if (index != -1 && m_estat[index] == OCUPAT && m_diccionari[index].first == clau)
	{
		definicio = m_diccionari[index].second;
		return true;
	}

	definicio = "";
	return false;
}

int Hash::cerca(const string& clau) const
{
	int indexi = codi(clau);
	int index = indexi;
	int vegades = 1;

	while (m_estat[index] != LLIURE)
	{
		if (m_estat[index] == OCUPAT && m_diccionari[index].first == clau)
			return index;

		index = codi2(indexi, vegades);
		vegades++;

		if (vegades >= m_maxElements)
			break;
	}
	return index;
}

int Hash::codi(string s) const
{
	unsigned long valor = 0;
	for (int i = 0; i < s.size(); i++)
	{
		valor += (s[i] * pow(2, i));
		valor = valor % m_maxElements;
	}
	return valor;
}

int Hash::codi2(int index, int vegades) const
{
	return (int)(index + pow(vegades, 2)) % m_maxElements;
}

void Hash::insertIntern(const string& clau, const string& descripcio)
{
	int indexi = codi(clau);
	int index = indexi;
	int vegades = 1;
	while ((m_estat[index] == OCUPAT) && (vegades < m_maxElements))
	{
		index = codi2(indexi, vegades);
		vegades++;
	}
	if (vegades >= m_maxElements) throw "ERROR: NO S'HA TROBAT POSICIO PER INSERIR EL HASH";

	m_diccionari[index].first = clau;
	m_diccionari[index].second = descripcio;
	m_estat[index] = OCUPAT;
	m_numOcupats++;
}

string& Hash::operator[](const string& clau)
{
	int index = cerca(clau);

	if (m_estat[index] == OCUPAT && m_diccionari[index].first == clau)
	{
		return m_diccionari[index].second;
	}

	insertIntern(clau, m_descripcioDefecte);

	return m_descripcioDefecte;
}

bool Hash::esborra(const string& clau)
{
	int index = codi(clau);

	if (m_diccionari[index].first == clau)
	{
		m_diccionari[index].first = "";
		m_diccionari[index].second = "";
		m_numOcupats--;
		return true;
	}

	return false;

}


ostream& operator<<(ostream& out, const Hash& h)
{
	for (int i = 0; i < h.m_diccionari.size(); i++)
	{
		if (h.m_diccionari[i].first != "")
		{
			out << "POS: " << i << "  CLAU: " << h.m_diccionari[i].first << "  VALOR: " << h.m_diccionari[i].second << endl;
		}
	}

	return out;
}
