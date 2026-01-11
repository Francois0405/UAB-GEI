#pragma once
#include <string>
#include "Data.h"

using namespace std;

class Prestec
{
public:
	Prestec();
	Prestec(const string& userID, const string& codi, const Data& dataPrestec, const Data& dataRetorn, const int& nExemplar);
	~Prestec() {}
	
	void setUserID(const string& userID) { m_userID = userID; }
	void setCodiPub(const string& codiPub) { m_codiPub = codiPub; }
	void setDataPrestec(const Data& dataPrestec) { m_dataPrestec = dataPrestec; }
	void setDataRetorn(const Data& dataRetorn) { m_dataRetorn = dataRetorn; }
	void setNExemplar(int nExemplar) { m_nExemplar = nExemplar; }

	string getUserID() const { return m_userID; }
	string getCodiPub() const { return m_codiPub; }
	Data getDataPrestec() const { return m_dataPrestec; }
	Data getDataRetorn() const { return m_dataRetorn; }
	int getNExemplar() const { return m_nExemplar; }
private:
	string m_userID;
	string m_codiPub;
	Data m_dataPrestec;
	Data m_dataRetorn;
	int m_nExemplar;
};