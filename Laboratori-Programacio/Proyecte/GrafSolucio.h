#pragma once
#include "pch.h"
#include "Util.h"
#include "PuntDeInteresBase.h"

#include <vector>
#include <stack>

using namespace std;

class MapaSolucio;
// Graf no dirigit amb matriu d'adjacencia
class GrafSolucio
{
public:
	GrafSolucio();
	GrafSolucio(const vector<Coordinate>& nodes, const vector<vector<double>>& matAdj);
	GrafSolucio(MapaSolucio& mapaSolucio); 

	GrafSolucio(const GrafSolucio& graf);
	~GrafSolucio() {};

	vector<vector<double>> getMatAdj() { return m_matAdj; }
	vector<Coordinate> getNodes() { return m_nodes; }
	size_t getNumArestes() { return m_numArestes; }
	size_t getNumNodes() { return m_numNodes; }
	
	void setNumNodes(size_t numNodes) { m_numNodes = numNodes; }
	void setNumArestes(size_t numArestes) { m_numArestes = numArestes; }

	GrafSolucio& operator=(const GrafSolucio& graf);
	void afegirAresta(const Coordinate& node1, const Coordinate& node2);
	void eliminarAresta(const Coordinate& node1, const Coordinate& node2);

	void afegirNode(const Coordinate& node);
	void eliminarNode(const Coordinate& node);

	int inM_Nodes(const Coordinate& node);

	void camiMesCurt(const Coordinate& node1, const Coordinate& node2, stack<Coordinate>& cami);
	size_t minDistance(const vector<double>& dist, const vector<bool>& visitat) const;
	void dijkstraModif(size_t node1, size_t node2, vector<double>& dist, vector<size_t>& anterior);

private:
	vector<vector<double>> m_matAdj;
	vector<Coordinate> m_nodes;
	size_t m_numNodes;
	size_t m_numArestes;
};