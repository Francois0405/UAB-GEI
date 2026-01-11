#include "Biblioteca.h"
#include "Publicacio.h"
#include "Llibre.h"
#include "Revista.h"
#include <fstream>

void Biblioteca::llegirPublicacions(const string& nomFitxer)
{
	ifstream fitxer(nomFitxer);
	if (fitxer.is_open())
	{
		string tipus; // L / R
		string codi;
		string titol;
		while (!fitxer.eof())
		{
			fitxer >> tipus >> codi >> titol;
			if (tipus == "L")
			{
				//Llibre
				string autor;
				int nCopies;
				int nDiesPrestec;

				fitxer >> autor >> nCopies >> nDiesPrestec;
				m_publicacions.push_back(new Llibre(codi, titol, autor, nCopies, nDiesPrestec));
			}
			else if (tipus == "R")
			{
				//Revista
				string periodicitat;
				int nExemplar;
				vector<int> exemplars;
				int exemplar;

				fitxer >> periodicitat >> nExemplar;
				for (int i = 0; i < nExemplar; i++)
				{
					fitxer >> exemplar;
					exemplars.push_back(exemplar);
				}
				Revista* revista = new Revista(codi, periodicitat, nExemplar, exemplars);
				revista->setTitol(titol);
				m_publicacions.push_back(revista);
			}
		}
		fitxer.close();
	}
}

bool Biblioteca::prestar(const string& idUsuari, const string& codi, const Data& dataPrestec, Data& dataRetorn, int nExemplar)
{
    for (auto pub : m_publicacions) {
        if (pub->getCodi() == codi) {
            if (pub->potPrestar()) {
                pub->prestar();
                dataRetorn = dataPrestec + pub->getDiesPrestec();

                Prestec prestec(idUsuari, codi, dataPrestec, dataRetorn, nExemplar);
                m_prestecs.push_back(prestec);

                return true;
            }
        }
    }
    return false;
}

bool Biblioteca::retornar(const string& idUsuari, const string& codi, const Data& data, bool& dataCorrecta, int nExemplar)
{
    for (auto it = m_prestecs.begin(); it != m_prestecs.end(); it++) {
        if (it->getUserID() == idUsuari && it->getCodiPub() == codi && it->getNExemplar() == nExemplar) {
            dataCorrecta = (data < it->getDataRetorn() || data == it->getDataRetorn());

			for (auto pub : m_publicacions) {
                if (pub->getCodi() == codi) {
                    pub->retornar();
                    break;
                }
            }

            m_prestecs.erase(it);
            return true;
        }
    }
    return false;
}