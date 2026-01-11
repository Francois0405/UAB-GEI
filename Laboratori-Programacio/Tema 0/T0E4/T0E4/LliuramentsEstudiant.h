#pragma once
#include <string>
#include <forward_list>
#include "Tramesa.h"
using namespace std;

/*
* Class LliuramentsEstudiant
* Aquesta classe representa els lliuraments d'un estudiant.
* Conté el NIU de l'estudiant, la nota i una llista de trameses.
* 
* Atributs:
* - m_niu: string que representa el NIU de l'estudiant.
* - m_nota: float que representa la nota de l'estudiant.
* - m_trameses: forward_list de Tramesa que representa les trameses de l'estudiant.
*/

class LliuramentsEstudiant
{
public:
	LliuramentsEstudiant() : m_niu(""), m_nota(0.0) {};
	void setNiu(const string& niu) { m_niu = niu; }
	void setNota(const float nota) { m_nota = nota; }
	string getNiu() const { return m_niu; }
	float getNota() const { return m_nota; }
	void afegeixTramesa(const string& fitxer, const string& data);
	bool consultaTramesa(const string& data, string& fitxer);
	bool eliminaTramesa(const string& data);
private:
	string m_niu;
	float m_nota;
	forward_list<Tramesa> m_trameses;
};

