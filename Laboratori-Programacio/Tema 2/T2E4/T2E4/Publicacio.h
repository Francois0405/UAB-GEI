#pragma once
#include <string>

using namespace std;

class Publicacio {
public:
    Publicacio(): m_codi("N/A"), m_titol("N/A") {}
    Publicacio(const string& codi, const string& titol) {
		m_codi = codi;
		m_titol = titol;
    }
    virtual ~Publicacio() {}

	void setCodi(const string& codi) { m_codi = codi; }
	void setTitol(const string& titol) { m_titol = titol; }
    string getCodi() const { return m_codi; }
    string getTitol() const { return m_titol; }
    virtual int getDiesPrestec() const = 0;
    virtual bool potPrestar() const = 0;
    virtual void prestar() = 0;
    virtual void retornar() = 0;
private:
    string m_codi;
    string m_titol;
};