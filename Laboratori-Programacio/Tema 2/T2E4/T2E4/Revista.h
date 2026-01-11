#pragma once
#include "Publicacio.h"
#include <string>
#include <vector>

using namespace std;

class Revista : public Publicacio
{
public:
	Revista() : m_periodicitat("N/A"), m_nExemplar(0) {}
	Revista(const string& codi, const string& periodicitat, int nExemplar, vector<int> exemplars)
	{
		setCodi(codi);
		setTitol("");
		m_periodicitat = periodicitat;
		m_nExemplar = nExemplar;
		m_exemplars = exemplars;
	}
	~Revista() {}

	string getPeriodicitat() const { return m_periodicitat; }
	void setPeriodicitat(const string& periodicitat) { m_periodicitat = periodicitat; }
	int getNExemplar() const { return m_nExemplar; }
	void setNExemplar(int nExemplar) { m_nExemplar = nExemplar; }
	vector<int> getExemplars() const { return m_exemplars; }
	void setExemplars(const vector<int>& exemplars) { m_exemplars = exemplars; }
	int getDiesPrestec() const override { return 30; }

	void afegeixExemplar(int nExemplar);
	
	bool potPrestar() const override;
	void prestar() override;
	void retornar() override;
private:
	string m_periodicitat;
	int m_nExemplar;
	vector<int> m_exemplars;
	vector<bool> m_prestat;
};