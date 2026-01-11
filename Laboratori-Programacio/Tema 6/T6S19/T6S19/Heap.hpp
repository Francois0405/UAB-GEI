#pragma once
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Heap {
public:
	Heap(size_t maxElements = 10) :m_numNodes(0), m_max(maxElements), m_data(maxElements) {};
	Heap(std::vector<T>& v);
	Heap(Heap<T>& h);
	~Heap() {};

	Heap<T>& operator=(const Heap<T>& h);

	T min() const { return (m_data[0]); }
	size_t mida() const { return m_numNodes; }
	size_t midaMax() const { return m_max; }
	bool buit() const { return m_numNodes == 0; }
	bool hihaEspai() const { return m_numNodes < m_max; }
	void read(string nomFitxer);

	friend std::ostream& operator<<(std::ostream& out, const Heap<T>& h)
	{
		if (h.m_numNodes == 0) { out << "|---->BUIT" << endl; }
		else	h.printRec(out, 0, 0);
		return out;
	}
	void insert(const T& el);
	void delMin();
	vector<T> ordenar();


protected:
	vector<T> m_data;
	size_t m_max; //indica nombre total de nodes: array va de 0 a m_max-1
	size_t m_numNodes; //indica numero de Nodes: inicialment 0 


	size_t pare(size_t pos) const { return ((pos - 1) / 2); }
	size_t fillEsq(size_t pos) const { return ((2 * pos) + 1); }
	size_t fillDret(size_t pos) const { return ((2 * pos) + 2); }
	virtual void intercanvia(size_t pos1, size_t pos2) { std::swap(m_data[pos1], m_data[pos2]); }
	std::ostream& printRec(std::ostream& out, size_t pos, size_t n) const;
	void descendir(size_t pos);
	void descendirIter(size_t posAct);
	void make_heap();
};

template<class T>
Heap<T>::Heap(Heap<T>& h)
{//constructor de copia
	m_data = h.m_data;
	m_max = h.m_max;
	m_numNodes = h.m_numNodes;

}

template<class T>
void Heap<T>::insert(const T& el)
{
	//TO DO Exercici 1
	size_t posAct = m_numNodes;
	if (!hihaEspai())
	{
		m_data.push_back(el);
		m_max++;
		// Se redimensiona el vector
	}
	else
	{
		m_data[m_numNodes] = el;
	}
	m_numNodes++;

	while (posAct != 0 && m_data[posAct] < m_data[pare(posAct)])
	{
		//intercanbiamos padre /poact
		intercanvia(posAct, pare(posAct));
		posAct = pare(posAct);
	}
}

template<class T>
void Heap<T>::delMin()
{
	//TO DO Exercici 2
	// De los dos bajamos por el menor
	if (buit())
		return;

	intercanvia(0, m_numNodes - 1);
	m_numNodes--;

	descendir(0);
}

template<class T>
void Heap<T>::descendir(size_t posAct)
{
	//TO DO Exercici 2
	//A solucio hem posat descendirRec o descendirIter 
	//per diferenciar dos possibles solucions 
	//però la que trieu es dirà descendir

	size_t fEsq = fillEsq(posAct);
	size_t fDret = fillDret(posAct);
	size_t mesPetit = posAct;

	if (fEsq < m_numNodes && m_data[fEsq] < m_data[mesPetit])
	{
		mesPetit = fEsq;
	}
	if (fDret < m_numNodes && m_data[fDret] < m_data[mesPetit])
	{
		mesPetit = fDret;
	}
	if (mesPetit != posAct) {
		intercanvia(posAct, mesPetit);
		descendir(mesPetit);
	}
}

template<class T>
void Heap<T>::descendirIter(size_t posAct)
{
	while (true)
	{
		size_t fEsq = fillEsq(posAct);
		size_t fDret = fillDret(posAct);
		int mesPetit = posAct;
		if (fEsq < m_numNodes)
		{
			if (m_data[fEsq] < m_data[mesPetit])
				mesPetit = fEsq;
		}
		if (fDret < m_numNodes) {
			if (m_data[fDret] < m_data[mesPetit])
				mesPetit = fDret;
		}
		if (mesPetit != posAct) {
			intercanvia(posAct, mesPetit);
			posAct = mesPetit;
		}
		else {
			return;
		}
	}
}

template<class T>
Heap<T>::Heap(std::vector<T>& v): m_numNodes(v.size()), m_max(v.size()), m_data(v)
{
	//TO DO Exercici 3.

	for (size_t i = 0; i < m_max; i++)
	{
		m_data[i] = v[i];
	}

	make_heap();
}

template<class T>
void Heap<T>::make_heap()
{
	//TO DO Exercici 3
	size_t n = m_numNodes;

	if (n <= 1) 
		return;

	for (size_t i = (n - 1) / 2; i >= 0; i--)
	{
		descendir(i);

		if (i == 0) 
			break;
	}
}

template<class T>
vector<T> Heap<T>::ordenar()
{
	//TO DO Exercici 4
	while (m_numNodes > 0)
		delMin();

	return m_data;
}

template<class T>
Heap<T>& Heap<T>::operator=(const Heap<T>& h)
{
	if (this != &h)
	{
		m_data = h.m_data;
		m_max = h.m_max;
		m_numNodes = h.m_numNodest;

	}
	return *this;
}


/////////////////////////////////////////////////////////////////////////////
// read(nomFitxer):                                                        //
//                 Metode public que obre fitxer i llegeix Heap            //
//Lectura d'un fitxer a on tindrem                                         //
//nombre elements maxim admet Heap                                         //
//nombre elements que cont� el Heap                                        //
//Valors elements                                                          //
/////////////////////////////////////////////////////////////////////////////
template<class T>
void Heap<T>::read(string nomFitxer)
{
	ifstream fitxerNodes;

	fitxerNodes.open(nomFitxer.c_str());
	if (fitxerNodes.is_open())
	{
		//Llegim maxim nombre de nodes i nombre nodes actual
		fitxerNodes >> m_max;
		fitxerNodes >> m_numNodes;
		m_data.resize(m_numNodes, T());

		size_t i = 0;
		while ((!fitxerNodes.eof()) && (i < m_numNodes))
		{
			fitxerNodes >> m_data[i];
			i++;
		}
		fitxerNodes.close();
	}
}

/////////////////////////////////////////////////////////////////////////////
// printRec(int pos, int n)                                                 //
//         Metode privat que escriu HEap per pantalla de forma recursiva   //
// |--arrel                                                                //
// |---->FillDret1                                                         //
// |------>FillDret2                                                       //
// |------>FillEsquerre2                                                   //
// |---->FillEsquerre1                                                     //
/////////////////////////////////////////////////////////////////////////////
template<class T>
std::ostream& Heap<T>::printRec(std::ostream& out, size_t pos, size_t n) const
{
	if (pos < m_numNodes)
	{//Pintem arbre
		for (size_t i = 0; i < n; i++)
		{
			out << "|--";
		}
		out << "|-->" << m_data[pos] << endl;
		if (((2 * pos) + 1) <= m_max)
		{//printem subarbre esquerre
			printRec(out, fillEsq(pos), n + 1);
		}
		if (((2 * pos) + 2) < m_max)
		{//printem subarbre dret
			printRec(out, fillDret(pos), n + 1);
		}
	}
	return out;
}
