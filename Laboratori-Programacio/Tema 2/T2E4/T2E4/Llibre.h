#pragma once
#include "Publicacio.h"

class Llibre : public Publicacio
{
public:
	Llibre(): m_titol("N/A"), m_autor("N/A"), m_nCopies(0), m_nDiesPrestec(0) {}
	Llibre(const string& codi, const string& titol, const string& autor, int nCopies, int nDiesPrestec)
	{
		setCodi(codi);
		m_titol = titol;
		m_autor = autor;
		m_nCopies = nCopies;
		m_nDiesPrestec = nDiesPrestec;
		m_nDies = 0;
	}
	~Llibre() {}

	string getTitol() const { return m_titol; }
	void setTitol(const string& titol) { m_titol = titol; }
	string getAutor() const { return m_autor; }
	void setAutor(const string& autor) { m_autor = autor; }
	int getNCopies() const { return m_nCopies; }
	void setNCopies(int nCopies) { m_nCopies = nCopies; }
	int getNDiesPrestec() const { return m_nDiesPrestec; }
	int getDiesPrestec() const override { return m_nDiesPrestec; }
	void setNDiesPrestec(int nDiesPrestec) { m_nDiesPrestec = nDiesPrestec; }

	bool potPrestar() const override { return m_nCopies > 0; }
	void prestar() override;
	void retornar() override { m_nCopies++; }
private:
	string m_titol;
	string m_autor;
	int m_nCopies;
	int m_nDies;
	int m_nDiesPrestec;
};