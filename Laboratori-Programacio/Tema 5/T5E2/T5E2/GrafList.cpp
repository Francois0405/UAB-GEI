#include "GrafList.h"
#include <iomanip>

struct ComparaPair
{
	ComparaPair(int val) : m_valor(val) {}
	bool operator()(const std::pair<int, int>& elem) const
	{
		return m_valor == elem.first;
	}
	bool operator==(const std::pair<int, int>& elem) const
	{
		return m_valor == elem.first;
	}
private:
	int m_valor;
};

Graf::Graf(bool dirigit)
{
	m_numNodes = 0;
	m_numArestes = 0;
	m_dirigit = dirigit;
}

Graf::Graf(const vector<string>& nodes, const vector<vector<int>>& parNodes, bool dirigit)
{
	m_numNodes = nodes.size();
	m_nodes.resize(m_numNodes);
	m_veins.resize(m_numNodes);
	m_dirigit = dirigit;
	m_numArestes = parNodes.size();

	for (int i = 0; i < m_numNodes; i++)
	{
		m_nodes[i] = nodes[i];
	}
	for (int j = 0; j < parNodes.size(); j++)
	{
		if ((parNodes[j][0] < m_numNodes) && (parNodes[j][1] < m_numNodes) &&
			(parNodes[j][0] >= 0) && (parNodes[j][1] >= 0))
		{
			m_veins[parNodes[j][0]].emplace_back(pair<int, int>(parNodes[j][1], 1));
			if (!dirigit)
			{
				m_veins[parNodes[j][1]].emplace_back(pair<int, int>(parNodes[j][0], 1));
			}
		}
	}
}
Graf::Graf(const vector<string>& nodes, const vector<vector<int>>& parNodes, const vector<int>& pesos, bool dirigit)
{
	m_numNodes = nodes.size();
	m_nodes.resize(m_numNodes);
	m_veins.resize(m_numNodes);
	m_dirigit = dirigit;
	m_numArestes = parNodes.size();

	for (int i = 0; i < m_numNodes; i++)
	{
		m_nodes[i] = nodes[i];
	}
	for (int j = 0; j < parNodes.size(); j++)
	{
		if ((parNodes[j][0] < m_numNodes) && (parNodes[j][1] < m_numNodes) &&
			(parNodes[j][0] >= 0) && (parNodes[j][1] >= 0))
		{
			m_veins[parNodes[j][0]].emplace_back(pair<int, int>(parNodes[j][1], pesos[j]));
			if (!dirigit)
			{
				m_veins[parNodes[j][1]].emplace_back(pair<int, int>(parNodes[j][0], pesos[j]));
			}
		}
	}
}
Graf::~Graf()
{
}

void Graf::inserirAresta(int posNode1, int posNode2)
{
	if ((posNode1 < m_numNodes) && (posNode2 < m_numNodes) && (posNode1 >= 0) && (posNode2 >= 0))
	{
		m_veins[posNode1].emplace_back(pair<int, int>(posNode2, 1));
		if (!m_dirigit)
		{
			m_veins[posNode2].emplace_back(pair<int, int>(posNode1, 1));
		}
		m_numArestes++;
	}
}

void Graf::inserirAresta(int posNode1, int posNode2, int pes)
{
	if ((posNode1 < m_numNodes) && (posNode2 < m_numNodes) && (posNode1 >= 0) && (posNode2 >= 0))
	{
		m_veins[posNode1].emplace_back(pair<int, int>(posNode2, pes));
		if (!m_dirigit)
		{
			m_veins[posNode2].emplace_back(pair<int, int>(posNode1, pes));
		}
		m_numArestes++;
	}
}


void Graf::eliminarAresta(int posNode1, int posNode2)
{
	list<pair<int, int>>::iterator itAre = find_if(m_veins[posNode1].begin(), m_veins[posNode1].end(), ComparaPair(posNode2));
	if (itAre != m_veins[posNode1].end())
	{
		m_veins[posNode1].erase(itAre);
		m_numArestes--;
	}
	if (!m_dirigit)
	{
		itAre = find_if(m_veins[posNode2].begin(), m_veins[posNode2].end(), ComparaPair(posNode1));
		if (itAre != m_veins[posNode2].end())
		{
			m_veins[posNode2].erase(itAre);
		}
	}
}

void Graf::afegirNode(const string& node)
{
	m_nodes.push_back(node);
	m_numNodes++;
	m_veins.resize(m_numNodes);
}


void Graf::eliminarNode(const string& node)
{
	//busquem la posici� del node a esborrar
	vector<string>::iterator it;

	it = find(m_nodes.begin(), m_nodes.end(), node);
	//mirem si node existeix
	if (it != m_nodes.end())
	{
		//Obtenim index del node
		int nodeIndex = it - m_nodes.begin();

		// eliminem el node del vector de nodes
		m_nodes.erase(it);
		//Eliminem arestes desde el node
		m_veins.erase(m_veins.begin() + nodeIndex);
		//Eliminem arestes cap al node

		for (int i = 0; i < m_veins.size(); i++)
		{//eliminem cada aresta sense ponderar
			m_veins[i].remove_if(ComparaPair(nodeIndex));
		}
		m_numNodes--;
	}
}

vector<vector<string>> Graf::cicles()
{
	vector<vector<string>> result;
	vector<string> claveCiclos;

	for (int i = 0; i < m_numNodes; i++)
	{
		for (auto vei : m_veins[i])
		{
			int j = vei.first;
			if (i == j) continue;
			
			// AHORA ITERAMOS EN LA LINIA DEL NODO J
			for (auto veiDelVei: m_veins[j])
			{ 
				int k = veiDelVei.first;
				if (j == k || k == i) continue;

				// AHORA ITERAMOS EN LA LINIA DEL NODO K
				for (auto veiDelVeiDelVei : m_veins[k])
				{
					if (veiDelVeiDelVei.first == i)
					{
						string clave = m_nodes[i] + m_nodes[j] + m_nodes[k];
						sort(clave.begin(), clave.end());
						if (find(claveCiclos.begin(), claveCiclos.end(), clave) == claveCiclos.end())
						{
							result.push_back({ m_nodes[i], m_nodes[j], m_nodes[k] });
							claveCiclos.push_back(clave);
						}
						break;
					}
				}
			}
		}
	}
	return result;
}

int Graf::grauOutNode(string node)
{
	bool trobat = false;
	int i = 0;
	while (!trobat && i < m_nodes.size())
	{
		if (m_nodes[i] == node)
			trobat = true;
		else
			i++;
	}
	return m_veins[i].size();
}

int Graf::grauInNode(string node)
{
	int count = 0;
	bool trobat = false;
	int ind = 0;
	while (!trobat && ind < m_nodes.size())
	{
		if (m_nodes[ind] == node)
			trobat = true;
		else
			ind++;
	}

	for (int i = 0; i < m_veins.size(); i++)
	{
		for (auto it : m_veins[i])
		{
			if (it.first == ind)
			{
				count++;
			}
		}
	}	
	return count;
}

void Graf::mostra()
{
	// imprimim el nom dels v�rtexs
	cout << "Graf: NUMNODES: " << m_numNodes << " ; NUMARESTES: " << m_numArestes << ":" << endl;
	cout << "=====NODES=====" << endl;
	for (int i = 0; i < m_numNodes; i++)
	{
		int espai = 20;
		if (i == 0) espai--;
		for (int dig = i; dig > 0; dig /= 10)
		{
			espai -= 1;
		}
		cout << i << ":" << setw(espai) << m_nodes[i] << " ";
		for (list<pair<int, int>>::iterator it = m_veins[i].begin(); it != m_veins[i].end(); it++)
		{
			cout << "-----> ( " << m_nodes[(*it).first] << "," << (*it).second << " )  ";
		}
		cout << endl;
	}
}

