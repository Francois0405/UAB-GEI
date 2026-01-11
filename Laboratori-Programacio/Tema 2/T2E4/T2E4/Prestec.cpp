#include "Prestec.h"

Prestec::Prestec()
    : m_userID(""), m_codiPub(""), m_dataPrestec(), m_dataRetorn(), m_nExemplar(0) {
}

Prestec::Prestec(const string& userID, const string& codi, const Data& dataPrestec, const Data& dataRetorn, const int& nExemplar)
    : m_userID(userID), m_codiPub(codi), m_dataPrestec(dataPrestec), m_dataRetorn(dataRetorn), m_nExemplar(nExemplar) {
}