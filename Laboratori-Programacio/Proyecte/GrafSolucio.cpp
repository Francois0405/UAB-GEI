#include "pch.h"
#include "GrafSolucio.h"
#include "MapaSolucio.h"
#include <limits>
#include <iostream>
#include <cmath>

// -------------------------------
// CONSTRUCTORES
// -------------------------------

GrafSolucio::GrafSolucio()
{
	m_numNodes = 0;
	m_numArestes = 0;
	cout << "Pues aqui te quedas, buena suerte para inicializar matAdj" << endl;
}

GrafSolucio::GrafSolucio(MapaSolucio& mapaSolucio)
{
	m_numNodes = 0;
	m_numArestes = 0;

	vector<CamiBase*> camins;
	mapaSolucio.getCamins(camins);
	for (size_t i = 0;i < camins.size();i++)
	{
		vector<Coordinate> coords = camins[i]->getCamiCoords();
		for (size_t j = 0; j < coords.size(); j++)
		{
			afegirNode(coords[j]);
			if (j > 0) {
				afegirAresta(coords[j], coords[j - 1]);
			}
		}
		// Añadimos la diagonal a 0
		m_matAdj[i][i] = 0;
	}
	
}

GrafSolucio::GrafSolucio(const vector<Coordinate>& nodes, const vector<vector<double>>& matAdj)
{
	m_nodes=nodes;
	m_matAdj = matAdj;
	m_numNodes = nodes.size();
	for (size_t i = 0;i < m_matAdj.size();i++)
	{
		for (size_t j = 0; j < m_matAdj[i].size(); j++)
		{
			if (m_matAdj[i][j] >= 0)
				m_numArestes++;
		}
	}
	m_numArestes /= 2;
}

GrafSolucio::GrafSolucio(const GrafSolucio& graf)
{
	m_numNodes = graf.m_numNodes;
	m_numArestes = graf.m_numArestes;
	m_matAdj = graf.m_matAdj;
	m_nodes = graf.m_nodes;
}

// -------------------------------
// MÈTODES PÚBLIQUES
// -------------------------------

int GrafSolucio::inM_Nodes(const Coordinate& node)
{
	/*auto it = find(m_nodes.begin(), m_nodes.end(), node);
	if (it == m_nodes.end())
		return -1;
	return distance(m_nodes.begin(), it);*/

	for (size_t i = 0; i < m_nodes.size(); i++) {
		const double epsilon = 1e-9;
		if (std::abs(m_nodes[i].lat - node.lat) < epsilon &&
			std::abs(m_nodes[i].lon - node.lon) < epsilon) {
			return static_cast<int>(i);
		}
	}
	return -1;
}

GrafSolucio& GrafSolucio::operator=(const GrafSolucio& graf)
{
	if (this != &graf)
	{
		m_matAdj = graf.m_matAdj;
		m_nodes = graf.m_nodes;
		m_numNodes = graf.m_numNodes;
		m_numArestes = graf.m_numArestes;
	}
	return *this;
}

void GrafSolucio::afegirAresta(const Coordinate& node1, const Coordinate& node2)
{
	int pos1 = inM_Nodes(node1);
	int pos2 = inM_Nodes(node2);
	if (pos1 >= 0 && pos2 >= 0)
	{
		m_matAdj[pos1][pos2] = Util::DistanciaHaversine(node1, node2);
		m_matAdj[pos2][pos1] = Util::DistanciaHaversine(node1, node2);
		m_numArestes++;
	}
}

void GrafSolucio::eliminarAresta(const Coordinate& node1, const Coordinate& node2)
{
	int pos1 = inM_Nodes(node1);
	int pos2 = inM_Nodes(node2);
	if (pos1 >= 0 && pos2 >= 0)
	{
		m_matAdj[pos1][pos2] = -1;
		m_matAdj[pos2][pos1] = -1;
		m_numArestes--;
	}


}

void GrafSolucio::afegirNode(const Coordinate& node)
{
	if (inM_Nodes(node) == -1)
	{
		m_nodes.push_back(node);
		m_numNodes++;
		m_matAdj.resize(m_numNodes);
		for (size_t i = 0; i < m_numNodes; i++)
		{
			// -1 Vol dir node no accesible
			m_matAdj[i].resize(m_numNodes,-1);
			m_matAdj[i][i] = 0;
		}
	}
}

void GrafSolucio::eliminarNode(const Coordinate& node)
{
	/*vector<Coordinate>::iterator it;

	it = find(m_nodes.begin(), m_nodes.end(), node);

	int pos = inM_Nodes(node);
	if (pos >= 0) // Si lo encontramos:
	{
		m_nodes.erase(m_nodes.begin() + pos);

		// eliminem la fila i la columna de la matriu d'adjacència corresponents
		// a aquest node
		m_matAdj.erase(m_matAdj.begin() + pos); // Fila

		for (int i = 0; i < m_matAdj.size(); i++)
		{
			m_matAdj[i].erase(m_matAdj[i].begin() + pos);
		}
		m_numNodes--;
	}*/
	int pos = inM_Nodes(node);  
	if (pos >= 0)
	{
		m_nodes.erase(m_nodes.begin() + pos);
		m_matAdj.erase(m_matAdj.begin() + pos);

		for (size_t i = 0; i < m_matAdj.size(); i++)
		{
			m_matAdj[i].erase(m_matAdj[i].begin() + pos);
		}
		m_numNodes--;
	}
}

void GrafSolucio::camiMesCurt(const Coordinate& node1, const Coordinate& node2, stack<Coordinate>& cami)
{
	/*//OMPLIR
	auto itNode1 = find(m_nodes.begin(), m_nodes.end(), node1);
	auto itNode2 = find(m_nodes.begin(), m_nodes.end(), node2);

	if (itNode1 != m_nodes.end() && itNode2 != m_nodes.end())
	{
		size_t posNode = distance(m_nodes.begin(), itNode1);
		size_t posNode2 = distance(m_nodes.begin(), itNode2);
		vector<size_t> anterior;
		vector<int> vDist;

		dijkstraModif(posNode, posNode2, vDist, anterior);
		size_t it = posNode2;
		cami.push(m_nodes[posNode2]);

		while (it != posNode)
		{
			cami.push(m_nodes[anterior[it]]);
			it = anterior[it];
		}
	}*/
	int posNode = inM_Nodes(node1);
	int posNode2 = inM_Nodes(node2);

	if (posNode >= 0 && posNode2 >= 0)
	{
		vector<size_t> anterior;
		vector<double> vDist;

		dijkstraModif(static_cast<size_t>(posNode), static_cast<size_t>(posNode2), vDist, anterior);
		size_t it = posNode2;
		cami.push(m_nodes[posNode2]);

		while (it != posNode)
		{
			cami.push(m_nodes[anterior[it]]);
			it = anterior[it];
		}
	}
}

size_t GrafSolucio::minDistance(const vector<double>& dist, const vector<bool>& visitat) const
{
	// Initialize min value, lo vamos remplazando.
	double min = DBL_MAX;
	size_t minIndex = -1;

	//OMPLIR
	for (size_t i = 0; i < m_numNodes; i++)
	{
		if (dist[i] < min && !visitat[i])
		{
			min = dist[i];
			minIndex = i;
		}
	}

	return minIndex;
}

void GrafSolucio::dijkstraModif(size_t node1, size_t node2, vector<double>& dist, vector<size_t>& anterior)
{
	//OMPLIR
	dist.resize(m_numNodes, DBL_MAX);
	anterior.resize(m_numNodes, -1);
	vector<bool> visitat(m_numNodes, false);
	dist[node1] = 0;
	anterior[node1] = node1;
	size_t pos = minDistance(dist, visitat);

	while (pos != node2)
	{
		pos = minDistance(dist, visitat);
		visitat[pos] = true;
		for (size_t j = 0; j < m_numNodes; j++)
		{
			if (m_matAdj[pos][j] > 0)
			{
				if (dist[j] > (dist[pos] + m_matAdj[pos][j]) && !visitat[j])
				{
					dist[j] = (dist[pos] + m_matAdj[pos][j]);
					anterior[j] = pos;
				}
			}
		}
	}
}