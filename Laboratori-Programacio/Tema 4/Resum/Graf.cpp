#include "Graf.h"

const int Graf::DISTMAX{ numeric_limits<int>::max() };

Graf::Graf()
{
    m_numNodes = 0;
    m_numArestes = 0;
    m_dirigit = false;
}

Graf::Graf(const vector<string>& nodes, const vector<vector<int>>& parelles_nodes, bool dirigit)
{
    m_nodes = nodes;
    m_numNodes = m_nodes.size();
    m_numArestes = parelles_nodes.size();
    m_dirigit = dirigit;
    crearMatriu(parelles_nodes);
}

Graf::Graf(const vector<string>& nodes, const vector<vector<int>>& parelles_nodes, const vector<int>& pesos, bool dirigit)
{
    m_nodes = nodes;
    m_numNodes = m_nodes.size();
    m_numArestes = parelles_nodes.size();
    m_dirigit = dirigit;
	crearMatriu(parelles_nodes, pesos);
}

Graf::~Graf() {}

void Graf::crearMatriu(const vector<vector<int>>& parelles)
{
	m_matriuAdj.resize(m_numNodes);
	for (auto &it : m_matriuAdj)
	{
		it.resize(m_numNodes);
	}
	for (size_t i = 0; i < parelles.size(); i++)
	{
		m_matriuAdj[parelles[i][0]][parelles[i][1]] = 1;
		if (!m_dirigit)
			m_matriuAdj[parelles[i][1]][parelles[i][0]] = 1;
	}
}

void Graf::crearMatriu(const vector<vector<int>>& parelles, const vector<int>& pesos)
{
	m_matriuAdj.resize(m_numNodes);
	for (auto &it : m_matriuAdj)
	{
		it.resize(m_numNodes);
	}
	for (size_t i = 0; i < parelles.size(); i++)
	{
		m_matriuAdj[parelles[i][0]][parelles[i][1]] = pesos[i];
		if (!m_dirigit)
			m_matriuAdj[parelles[i][1]][parelles[i][0]] = pesos[i];
	}
}

void Graf::inserirAresta(int posNode1, int posNode2, int pes)
{
    if (posNode1 >= m_numNodes || posNode2 >= m_numNodes) {
        throw runtime_error("Índice de nodo fuera de rango");
    }

    m_matriuAdj[posNode1][posNode2] = pes;
    if (!m_dirigit)
        m_matriuAdj[posNode2][posNode1] = pes;
}

void Graf::eliminarAresta(int posNode1, int posNode2)
{
    m_matriuAdj[posNode1][posNode2] = 0;
    if (!m_dirigit)
        m_matriuAdj[posNode2][posNode1] = 0;
}

void Graf::afegirNode(const string& node)
{
    //m_nodes.resize(m_numNodes);
    m_nodes.push_back(node);

    // add a row
    m_matriuAdj.push_back(vector<int>(m_numNodes));

    m_numNodes++;

    //m_matriuAdj.resize(m_numNodes);
    for (size_t i = 0; i < m_numNodes; i++) 
        m_matriuAdj[i].push_back(0);
}

void Graf::eliminarNode(const string& node)
{
    //busquem la posició del node a esborrar
    vector<string>::iterator it;

    it = find(m_nodes.begin(), m_nodes.end(), node);

    //eliminem el node del vector de nodes i de la matriu d'adjacència
    if (it != m_nodes.end())
    {
        size_t pos = distance(m_nodes.begin(), it);
        // eliminem el node del vector de nodes
        m_nodes.erase(m_nodes.begin() + pos);

        // eliminem la fila i la columna de la matriu d'adjacència corresponents
        // a aquest node
        m_matriuAdj.erase(m_matriuAdj.begin() + pos);

        m_numNodes--;

        for (size_t i = 0; i < m_numNodes; i++)
        {
            m_matriuAdj[i].erase(m_matriuAdj[i].begin() + pos);
        }
    }
}

size_t Graf::grauOutNode(string node)
{
	size_t grau = 0;

    vector<string>::iterator it;
    
    it = find(m_nodes.begin(),m_nodes.end(), node);
    
    if (it != m_nodes.end())
    {
        size_t pos = distance(m_nodes.begin(),it);
        for (size_t i = 0; i < m_numNodes; i++) {
            if (m_matriuAdj[pos][i] != 0)
                grau++;
        }
    }
    
	return grau;
}

size_t Graf::grauInNode(string node)
{
	size_t grau = 0;

    vector<string>::iterator it;
    
    it = find(m_nodes.begin(),m_nodes.end(), node);
    
    if (it != m_nodes.end())
    {
        size_t pos = distance(m_nodes.begin(),it);
        for (size_t i = 0; i < m_numNodes; i++) {
            if (m_matriuAdj[i][pos] != 0)
                grau++;
        }
    }
    
	return grau;
}

vector<vector<int>> Graf::cicles()
{
    vector<vector<int>> parades_cicles;

    for (int i = 0; i < m_matriuAdj.size();i++)
    {
        for (size_t j = i+1; j < m_matriuAdj[i].size();j++)
        {
            if (m_matriuAdj[i][j] >= 1)
            {
                for (size_t vei = j+1; vei < m_numNodes; vei++)
                {
                    if ((m_matriuAdj[vei][i] >= 1) && (m_matriuAdj[vei][j]))
                        parades_cicles.push_back({ i,(int)j,(int)vei });
                }
            }
        }
    }
    return parades_cicles;
}

void Graf::DFSRec(size_t pos, vector<string>& recorregut, vector<bool>& visitat)
{
    if (!visitat[pos])
    {
        visitat[pos] = true;
        recorregut.push_back(m_nodes[pos]);
        for (size_t i = 0; i < m_numNodes; i++)
        {
            if (m_matriuAdj[pos][i] != 0 && visitat[i] == false)
            {
                DFSRec(i, recorregut, visitat);
            }
        }
    }
}

void Graf::DFSPila(size_t posInicial, vector<string>& recorregut)
{
    vector<bool> visitat(m_numNodes, false);
    stack<size_t> pila;
    pila.push(posInicial);
    
    while (!pila.empty()) {
        size_t rec = pila.top();
        pila.pop();
        if(!visitat[rec]) {
            recorregut.push_back(m_nodes[rec]);
            visitat[rec] = true;
            for (size_t i = 0; i < m_numNodes; i++)
            {
                if (m_matriuAdj[rec][i] != 0 && visitat[i] == false)
                {
                    pila.push(i);
                }
            }
        }
    }
}

void Graf::DFS(const string& nodeInicial, vector<string>& recorregut, bool utilitza_recursivitat)
{
    auto it = find(m_nodes.begin(), m_nodes.end(), nodeInicial);
    
    if (it == m_nodes.end()) {
        throw runtime_error("No existeix el node " + nodeInicial + " dins del graf.");
    }

    size_t posicioInicial = distance(m_nodes.begin(), it);

    if (!utilitza_recursivitat) {
        DFSPila(posicioInicial, recorregut);
    }
    else {
        vector<bool> visitat;
        visitat.resize(m_numNodes, false);
        DFSRec(posicioInicial, recorregut, visitat);
    }
}

void Graf::BFS(const string& nodeInicial, queue<string>& recorregut)
{
    auto it = find(m_nodes.begin(), m_nodes.end(), nodeInicial);
    if (it != m_nodes.end())
    {
        size_t pos = distance(m_nodes.begin(), it);
        vector<bool> visitat(m_numNodes, false);
        visitat[pos] = true;
        queue<size_t> pendents;
        pendents.push(pos);
        
        while (!pendents.empty())
        {
            size_t nodeActual = pendents.front();
            pendents.pop();
            recorregut.push(m_nodes[nodeActual]);
            
            for (size_t col=0; col < m_numNodes; col++)
            {
                if ((m_matriuAdj[nodeActual][col] != 0 && (!visitat[col])))
                {
                    pendents.push(col);
                    visitat[col] = true;
                }
            }
        }
    }
}

size_t Graf::minDistance(const vector<int>& dist, const vector<bool>& visitat) const
{
    int min = DISTMAX;
    size_t minIndex = -1;

    for (size_t posVei = 0; posVei < m_numNodes; posVei++)
    {
        if (!visitat[posVei] && dist[posVei] <= min)
        {
            min = dist[posVei];
            minIndex = posVei;
        }
    }
    
    return minIndex;
}

void Graf::dijkstra(size_t node, vector<int>& dist)
{
    dist.resize(m_numNodes, DISTMAX);
    vector<bool> visitat(m_numNodes, false);
    dist[node] = 0;
    
    for (size_t count = 0; count < m_numNodes - 1; count++)
    {
        size_t posVeiAct = minDistance(dist, visitat);
        visitat[posVeiAct] = true;
        for (size_t posVei = 0; posVei < m_numNodes; posVei++)
        {
            if (m_matriuAdj[posVeiAct][posVei] != 0)
            {
                if (!visitat[posVei])
                {
                    if (dist[posVeiAct] + m_matriuAdj[posVeiAct][posVei] < dist[posVei])
                    {
                        dist[posVei] = dist[posVeiAct] + m_matriuAdj[posVeiAct][posVei];
                    }
                }
            }
        }
    }
}

void Graf::dijkstra(size_t node, vector<int>& dist, vector<size_t>& anterior)
{
    dist.resize(m_numNodes, DISTMAX);
    anterior.resize(m_numNodes, -1);
    vector<bool> visitat(m_numNodes, false);
    
    dist[node] = 0;
    anterior[node] = node;
    
    for (size_t count = 0; count < m_numNodes - 1; count++)
    {
        size_t posVeiAct = minDistance(dist, visitat);
        visitat[posVeiAct] = true;
        
        for (size_t posVei = 0; posVei < m_numNodes; posVei++)
        {
            if (m_matriuAdj[posVeiAct][posVei] != 0 && !visitat[posVei])
            {
                int newDist = dist[posVeiAct] + m_matriuAdj[posVeiAct][posVei];
                if (newDist < dist[posVei])
                {
                    dist[posVei] = newDist;
                    anterior[posVei] = posVeiAct;
                }
            }
        }
    }
}

void Graf::camiMesCurt(const string& node1, const string& node2, stack<string>& cami)
{
    vector<string>::iterator itNode1 = find(m_nodes.begin(), m_nodes.end(), node1);
    vector<string>::iterator itNode2 = find(m_nodes.begin(), m_nodes.end(), node2);

    if ((itNode1 != m_nodes.end()) && (itNode2 != m_nodes.end()))
    {
        size_t pos1 = distance(m_nodes.begin(), itNode1);
        size_t pos2 = distance(m_nodes.begin(), itNode2);
        vector<size_t> anterior;
        vector<int> vDist;
        
        dijkstra(pos1, vDist, anterior);
        
        size_t it = pos2;
        cami.push(m_nodes[it]);
        while (it != pos1 && anterior[it] != it)
        {
            it = anterior[it];
            cami.push(m_nodes[it]);
        }
    }
}

void Graf::dijkstraModif(size_t node1, size_t node2, vector<int>& dist, vector<size_t>& anterior)
{
    dist.resize(m_numNodes, DISTMAX);
    vector<bool> visitat(m_numNodes, false);
    
    anterior.resize(m_numNodes, -1);
    dist[node1] = 0; // Corrección: usar node1 en lugar de node
    anterior[node1] = node1; // Corrección: usar node1 en lugar de nodes
    
    for (size_t count = 0; count < m_numNodes - 1; count++)
    {
        size_t posVeiAct = minDistance(dist, visitat);
        visitat[posVeiAct] = true;
        
        if (posVeiAct == node2) return;
        
        for (size_t posVei = 0; posVei < m_numNodes; posVei++)
        {
            if (m_matriuAdj[posVeiAct][posVei] != 0 && !visitat[posVei])
            {
                int newDist = dist[posVeiAct] + m_matriuAdj[posVeiAct][posVei];
                if (newDist < dist[posVei])
                {
                    dist[posVei] = newDist;
                    anterior[posVei] = posVeiAct;
                }
            }
        }
    }
}

void Graf::mostra()
{
    int mida_c = 4;

    cout << setw(mida_c) << " ";
    for (size_t j = 0; j < m_numNodes; j++)
    {
        cout << setw(mida_c) << m_nodes[j] << " ";
    }
    cout << endl;

    for (size_t i = 0; i < m_numNodes; i++)
    {
        cout << setw(10) << m_nodes[i] << " ";
        for (size_t j = 0; j < m_numNodes; j++)
        {
            cout << setw(mida_c) << m_matriuAdj[i][j] << " ";
        }
        cout << endl;
    }
}

void Graf::printTotsCaminsFins(size_t pos1, size_t pos2, vector<bool>& visited, list<size_t>& paths, vector<list<string>>& camins_out)
{
	visited[pos1] = true;
    paths.push_back(pos1);
    if (pos1 != pos2) 
    {
        for (size_t i = 0; i < m_numNodes; i++)
        {
            if (m_matriuAdj[pos1][i] != 0)
            {
                if (visited[i] == false)
                {
                    printTotsCaminsFins(i, pos2, visited, paths, camins_out);
                }
            }
        }
    }
    else 
    {
        list<string> nodesCami;

        for (const auto& e1: paths) {
            cout << m_nodes[(e1)] << " ";
            nodesCami.push_back(m_nodes[(e1)]);
        }
        camins_out.push_back(nodesCami);
        cout << endl;
    }
    paths.pop_back();
    visited[pos1] = false;
}

void Graf::camins(string node1, string node2, vector<list<string>>& camins_out)
{
    vector<string>::iterator it1, it2;
    vector<bool> visited(m_numNodes, false);
    list<size_t> cami;
    
    
    if (grauOutNode(node1) == 0 || grauInNode(node2) == 0)
        return;

    it1 = find(m_nodes.begin(),m_nodes.end(), node1);   
    it2 = find(m_nodes.begin(),m_nodes.end(), node2);

    if ((it1 != m_nodes.end()) && (it2 != m_nodes.end()))
    {
        size_t posIni = distance(m_nodes.begin(),it1);
        size_t posFin = distance(m_nodes.begin(),it2);
        
        printTotsCaminsFins(posIni, posFin, visited, cami, camins_out);
    }
    // Buscamos en la lista de camino si en el mismo camino hay dos veces el mismo numero
    // nodos a los que puedo ir, nodos de mi fila
}