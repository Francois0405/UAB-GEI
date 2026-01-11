#include "Exercici.h"
#include <fstream>
using namespace std;

Exercici::Exercici(const Exercici& e)
{
	m_descripcio = e.m_descripcio;
	m_dataLimit = e.m_dataLimit;
	m_nEstudiants = e.m_nEstudiants;
	
	// m_lliuraments = e.m_lliuraments; ! ESTO ES SHALLOW COPY !
	// Por lo tanto hacemos un deepcopy
	if (e.m_lliuraments != nullptr)
	{
		m_lliuraments = new LliuramentsEstudiant[m_nEstudiants];
		for (int i = 0; i < m_nEstudiants; i++)
		{
			m_lliuraments[i] = e.m_lliuraments[i];
		}
	}
	else
	{
		m_lliuraments = nullptr;
	}
}

Exercici::~Exercici()
{
	delete[] m_lliuraments;
}

Exercici& Exercici::operator=(const Exercici& e)
{
	m_descripcio = e.m_descripcio;
	m_dataLimit = e.m_dataLimit;
	m_nEstudiants = e.m_nEstudiants;
	if (e.m_lliuraments != nullptr)
	{
		m_lliuraments = new LliuramentsEstudiant[m_nEstudiants];
		for (int i = 0; i < m_nEstudiants; i++)
		{
			m_lliuraments[i] = e.m_lliuraments[i];
		}
	}
	else
	{
		m_lliuraments = nullptr;
	}
	return *this;
}

void Exercici::inicialitzaEstudiants(const string& fitxerEstudiants)
{
	ifstream fitxer;
	fitxer.open(fitxerEstudiants);
	if (!fitxer.is_open())
	{
		throw runtime_error("No es pot obrir el fitxer: " + fitxerEstudiants);;
	}
	fitxer >> m_nEstudiants;

	// Llegim els nius
	if (m_lliuraments != nullptr)
		delete m_lliuraments;
	m_lliuraments = new LliuramentsEstudiant[m_nEstudiants];
	for (int i = 0; i < m_nEstudiants; i++)
	{
		string niu;
		fitxer >> niu;
		m_lliuraments[i].setNiu(niu);
	}
	fitxer.close();
}

int Exercici::buscaNiuLliurament(const string& niu)
{
	for (int i = 0; i < m_nEstudiants; i++)
	{
		if (m_lliuraments[i].getNiu() == niu)
		{
			return i;
		}
	}
	return -1;
}

bool Exercici::afegeixTramesa(const string& niu, const string& fitxer, const string& data)
{
	int i = buscaNiuLliurament(niu);
	if (i > -1)
	{
		m_lliuraments[i].afegeixTramesa(fitxer, data);
		return true;
	}
	else
	{
		/*LliuramentsEstudiant* nouArray = new LliuramentsEstudiant[m_nEstudiants + 1];
		if (m_lliuraments != nullptr && m_nEstudiants > 0)
		{
			for (i = 0; i < m_nEstudiants; i++)
			{
				nouArray[i] = m_lliuraments[i];
			}
		}
		m_nEstudiants++;
		nouArray[m_nEstudiants].setNiu(niu);
		nouArray[m_nEstudiants].afegeixTramesa(fitxer, data);
		delete[] m_lliuraments;
		m_lliuraments = nouArray;*/
		return false;
	}
}

bool Exercici::consultaTramesa(const string& niu, const string& data, string& fitxer)
{
	bool trobat = false;
	int i = buscaNiuLliurament(niu);
	if (i > -1)
	{
		trobat = m_lliuraments[i].consultaTramesa(data, fitxer);
	}
	return trobat;
}

bool Exercici::eliminaTramesa(const string& niu, const string& data)
{
	bool eliminat = false;
	int i = buscaNiuLliurament(niu);
	if (i > -1)
	{
		eliminat = m_lliuraments[i].eliminaTramesa(data);
	}
	return eliminat;
}
