#pragma once
#ifndef Graf_h
#define Graf_h

#include <vector>
#include <string>
#include <cstdio>
#include <list>
#include <queue>
#include <stack>

using namespace std;

class Graf
{
public:
    Graf();
    Graf(const vector<string>& nodes, const vector<vector<int>>& parellesNodes, bool dirigit);
	Graf(const vector<string>& nodes, const vector<vector<int>>& parellesNodes, const vector<int>& pesos, bool dirigit);
    ~Graf();

    const vector<string>& getNodes() const { return m_nodes; }
    const vector<vector<int>>& getMatriu() const { return m_matriuAdj; }
    bool esDirigit() const { return m_dirigit; }

    size_t getNumNodes() { return m_numNodes; }
    void setNumNodes(int numNodes) { m_numNodes = numNodes; }

    void inserirAresta(int posNode1, int posNode2, int pes = 1);
    void eliminarAresta(int posNode1, int posNode2);

    void afegirNode(const string& node);
    void eliminarNode(const string& node);

    size_t grauOutNode(string node);
	size_t grauInNode(string node);

    void BFS(const string& nodeInicial, queue<string>& recorregut);    
    void DFS(const string& nodeInicial, vector<string>& recorregut, bool utilitza_recursivitat);
    void DFSPila(size_t posInicial, vector<string>& recorregut);
    // - DFSPila (0) / DFSRec (1)

    void dijkstra(size_t node, vector<int>& dist);
    void dijkstra(size_t node, vector<int>& dist, vector<size_t>& anterior);
    void camiMesCurt(const string& node1, const string& node2, stack<string>& cami);

    vector<vector<int>> cicles();
    void camins(string node1, string node2,	vector<list<string>>& camins_out);
    void mostra();

    static const int DISTMAX;

private:
    vector<string> m_nodes;
    vector<vector<int>> m_matriuAdj;
    size_t m_numNodes;
    size_t m_numArestes;
   	bool m_dirigit;

    void crearMatriu(const vector<vector<int>>& parelles);
   	void crearMatriu(const vector<vector<int>>& parelles, const vector<int>& pesos);

	void DFSRec(size_t pos, vector<string>& recorregut, vector<bool>& visitat);
    void printTotsCaminsFins(size_t pos1, size_t pos2, vector<bool>& visited, list<size_t>& paths, vector<list<string>>& camins_out);

    size_t minDistance(const vector<int>& dist, const vector<bool>& visitat) const;
    void dijkstraModif(size_t node1, size_t node2, vector<int>& dist, vector<size_t>& anterior);
};


#endif /* Graf_h */