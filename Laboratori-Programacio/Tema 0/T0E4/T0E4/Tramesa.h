#pragma once
#include <string>
using namespace std;

/*
* Class Tramesa
* Aquesta classe representa una tramesa d'un estudiant.
* Conté el nom del fitxer i la data de la tramesa.
* Es fa servir a la classe LliuramentsEstudiant.
* 
* Atributs:
* - m_fitxer: string que representa el nom del fitxer de la tramesa.
* - m_data: string que representa la data de la tramesa.
*/

class Tramesa
{
public:
	Tramesa() : m_fitxer(""), m_data("") {};
	Tramesa(const string& fitxer, const string& data) : m_fitxer(fitxer), m_data(data) {}
	void setFitxer(const string& fitxer) { m_fitxer = fitxer; }
	void setData(const string& data) { m_data = data; }
	string getFitxer() const { return m_fitxer; }
	string getData() const { return m_data; }
private:
	string m_fitxer;
	string m_data;
};	