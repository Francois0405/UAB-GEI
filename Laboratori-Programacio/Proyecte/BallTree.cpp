#include "pch.h"
#include "BallTree.h"
#include <cmath> 

using namespace std;

bool BallTree::compareCoordinates(const Coordinate& c1, const Coordinate& c2)
{
	const double epsilon = 1e-9;
	return (std::abs(c1.lat - c2.lat) < epsilon) &&
		(std::abs(c1.lon - c2.lon) < epsilon);
}

void BallTree::construirArbre(const std::vector<Coordinate>& coordenades) {
    // TODO: Utilitza aquest metode per construir el teu BallTree
    // TODO: amb les coordenades que se us passen per parametre

	m_root = this;
    //caso base:
    if(coordenades.size()==1)
    {
        m_coordenades = coordenades;
        m_pivot = coordenades[0];
        m_radi=0.0;
        return;
    }
    //asignar todas la coord al nodo actual
    m_coordenades = coordenades;
        
    // 1. CALCULA EL PUNT CENTRAL DELS NODES
    m_pivot = Util::calcularPuntCentral(m_coordenades);
    
    // 2. CALCULA TOTES LES DISTANCIES RESPECTE EL PUNT CENTRAL
    Coordinate puntLlunyaA = m_pivot;
    for (size_t i = 0; i < m_coordenades.size(); i++)
    {
        double dist = Util::DistanciaHaversine(m_coordenades[i], m_pivot);
        if (dist > m_radi)
        {
            m_radi = dist;
            // 3. AGAFEM EL PUNT MÉS LLUNYA AL CENTRE
            puntLlunyaA = m_coordenades[i];
        }
    }

    // 4. CALCULEM TOTES LES DISTANCIES RESPECTE EL PUNT A
	Coordinate puntLlunyaB = puntLlunyaA;
    double distMax = 0;
	for (size_t i = 0; i < m_coordenades.size(); i++)
	{
		double dist = Util::DistanciaHaversine(m_coordenades[i], puntLlunyaA);
		if (dist > distMax)
		{
			distMax = dist;
			// 5. AGAFEM EL PUNT MÉS LLUNYA AL PUNT A
			puntLlunyaB = m_coordenades[i];
		}
	}

    /*// 5. PER CADA NODE:
    vector<Coordinate> leftCoord;
	vector<Coordinate> rightCoord;
    for (size_t i = 0; i < m_coordenades.size(); i++)
	{
        // 5.1 CALCULEM LA DISTANCIA AL PUNT A
		double distA = Util::DistanciaHaversine(m_coordenades[i], puntLlunyaA);
        // 5.1 CALCULEM LA DISTANCIA AL PUNT B
        double distB = Util::DistanciaHaversine(m_coordenades[i], puntLlunyaB);
        if (distA < distB)
		{
            // 5.3 SI distA < distB EL PUNT ES MÉS PROPER A 'A'
            auto it = find(leftCoord.begin(), leftCoord.end(), m_coordenades[i]);
            if (it == leftCoord.end())
            {
				// Ja està a l'esquerra
                leftCoord.push_back(m_coordenades[i]);
            }
		} 
        else
        {
            // 5.4 SI distA >= distB EL PUNT ES MÉS PROPER A 'B'
            auto it = find(rightCoord.begin(), rightCoord.end(), m_coordenades[i]);
            if (it == rightCoord.end())
            {
                // Ja està a l'esquerra
                rightCoord.push_back(m_coordenades[i]);
            }
        }
	}*/
	// 5. PER CADA NODE:
	vector<Coordinate> leftCoord;
	vector<Coordinate> rightCoord;
	for (size_t i = 0; i < m_coordenades.size(); i++)
	{
		// 5.1 CALCULEM LA DISTANCIA AL PUNT A
		double distA = Util::DistanciaHaversine(m_coordenades[i], puntLlunyaA);
		// 5.2 CALCULEM LA DISTANCIA AL PUNT B
		double distB = Util::DistanciaHaversine(m_coordenades[i], puntLlunyaB);

		if (distA < distB)
		{
			// 5.3 SI distA < distB EL PUNT ES MÉS PROPER A 'A'
			// Búsqueda manual
			bool encontrado = false;
			for (size_t j = 0; j < leftCoord.size() && !encontrado; j++) {
				if (this->compareCoordinates(leftCoord[j], m_coordenades[i])) {
					encontrado = true;
				}
			}
			if (!encontrado) {
				leftCoord.push_back(m_coordenades[i]);
			}
		}
		else
		{
			// 5.4 SI distA >= distB EL PUNT ES MÉS PROPER A 'B'
			// Búsqueda manual
			bool encontrado = false;
			for (size_t j = 0; j < rightCoord.size() && !encontrado; j++) {
				if (this->compareCoordinates(rightCoord[j], m_coordenades[i])) {
					encontrado = true;
				}
			}
			if (!encontrado) {
				rightCoord.push_back(m_coordenades[i]);
			}
		}
	}
    // 5.5 CONSTRUIM L'ARBRE
    if(!leftCoord.empty())
    {
        m_left = new BallTree();
        m_left->construirArbre(leftCoord);
    }
	if (!rightCoord.empty())
	{
		m_right = new BallTree();
		m_right->construirArbre(rightCoord);
	}
}

void BallTree::inOrdre(std::vector<std::list<Coordinate>>& out) {
    // TODO: TASCA 2
	// ORDRE: ESQUERRA, ARREL, DRET

    if (m_left != nullptr)
        m_left->inOrdre(out);
    out.push_back(std::list<Coordinate>(m_coordenades.begin(), m_coordenades.end()));
    if (m_right != nullptr)
        m_right->inOrdre(out);
}

void BallTree::preOrdre(std::vector<std::list<Coordinate>>& out) {
    // TODO: TASCA 2
	// ORDRE: ARREL, ESQUERRE, DRET
	out.push_back(list<Coordinate>(m_coordenades.begin(), m_coordenades.end()));
	if (m_left != nullptr)
        m_left->preOrdre(out);
	if (m_right != nullptr)
        m_right->preOrdre(out);
}

/*void BallTree::postOrdre(std::vector<std::list<Coordinate>>& out) {
    // TODO: TASCA 2
	// ORDRE: ESQUERRA, DRET, ARREL
    if (m_left != nullptr)
        m_left->preOrdre(out);
    if (m_right != nullptr)
        m_right->preOrdre(out);
    out.push_back(std::list<Coordinate>(m_coordenades.begin(), m_coordenades.end()));
}*/
void BallTree::postOrdre(std::vector<std::list<Coordinate>>& out) {
	// ORDRE: ESQUERRA, DRET, ARREL
	if (m_left != nullptr)
		m_left->postOrdre(out);  // Cambia preOrdre por postOrdre
	if (m_right != nullptr)
		m_right->postOrdre(out); // Cambia preOrdre por postOrdre
	out.push_back(std::list<Coordinate>(m_coordenades.begin(), m_coordenades.end()));
}

Coordinate BallTree::nodeMesProper(Coordinate targetQuery, Coordinate& Q, BallTree* ball) {
    // TODO: TASCA 3
    // Retornarà la Coordinate node-camí, emmagatzemada a bola, més propera al targetQuery
	if (ball == nullptr) 
        return Coordinate{ 0.0, 0.0 };

	double distPdiCentre = Util::DistanciaHaversine(targetQuery, ball->getPivot());
    double distPdiQ = Util::DistanciaHaversine(targetQuery, Q);
    if (distPdiCentre - ball->getRadi() >= distPdiQ)
    {
        return Q; // No cal explorar aquesta bola
	}
    //caso hoja
    if (ball->m_left == nullptr && ball->m_right == nullptr)
    {
        if (distPdiCentre < distPdiQ)
        {
            // No estamos seguro | ERROR | WARNING  
            Q = ball->getPivot();
        }
    }
    else
    {
        if (ball->m_left != nullptr && ball->m_right != nullptr)
        {
            double distEsq = Util::DistanciaHaversine(targetQuery, ball->m_left->m_pivot);
            double distDreta = Util::DistanciaHaversine(targetQuery, ball->m_right->m_pivot);

            Coordinate esqProper;
            Coordinate dretaProper;
            if (distEsq < distDreta)
            {
                esqProper = nodeMesProper(targetQuery, Q, ball->m_left);
                dretaProper = nodeMesProper(targetQuery, Q, ball->m_right);
            }
            else
            {
                dretaProper = nodeMesProper(targetQuery, Q, ball->m_right);
                esqProper = nodeMesProper(targetQuery, Q, ball->m_left);
            }
        }

    }
    return Q;
}