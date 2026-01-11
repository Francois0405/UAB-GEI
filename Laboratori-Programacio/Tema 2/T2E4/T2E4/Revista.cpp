#include "Revista.h"

void Revista::afegeixExemplar(int nExemplar) {
	m_exemplars.push_back(nExemplar);
    m_prestat.push_back(false);
	m_nExemplar++;
}

bool Revista::potPrestar() const {
    // Verificar si hay algún exemplar disponible
    for (bool prestado : m_prestat) {
        if (!prestado) return true;
    }
    return false;
}

void Revista::prestar() {
    for (size_t i = 0; i < m_prestat.size(); i++) {
        if (!m_prestat[i]) {
            m_prestat[i] = true;
            break;
        }
    }
}

void Revista::retornar() {
    // Buscar el exemplar prestado y marcarlo como disponible
    for (size_t i = 0; i < m_prestat.size(); i++) {
        if (m_prestat[i]) {
            m_prestat[i] = false;
            break;
        }
    }
}