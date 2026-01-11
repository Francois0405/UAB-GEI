#pragma once
#include <fstream>
#include <iostream>
#include<stack>
#include <sstream>
#include<string>

using namespace std;

template <typename T>
class Tree {
public:

	Tree();
	Tree(const Tree<T>& t);
	Tree(string nomFitxer);
	~Tree();
	bool isLeave() const { return ((m_left == nullptr) && (m_right == nullptr)); }
	bool isEmpty() const { return (m_data == nullptr); }
	Tree<T>* getRight() { return m_right; }
	Tree<T>* getLeft() { return m_left; }
	T& getData() { return (*m_data); }
	float avalua();
	void mostraExpressioRec(std::string& s, std::string& sep);
	void mostraExpressioIter(std::string& s, std::string& sep);
	bool cerca(const T& val, Tree<T>* valTrobat);

	friend std::ostream& operator<<(std::ostream& out, const Tree<T>& t)
	{
		t.coutArbreRec(0, out);
		return out;
	}
private:
	Tree<T>* m_left;
	Tree<T>* m_right;
	Tree<T>* m_father;
	T* m_data;

	void TreeRec(ifstream& fitxerNodes, int h, Tree<T>* father);
	std::ostream& coutArbreRec(int n, std::ostream& out) const;
};

template<typename T>
Tree<T>::Tree()
{//Inicialitzem tota l'estructura
	m_left = nullptr;
	m_right = nullptr;
	m_father = nullptr;
	m_data = nullptr;
}

template<typename T>
Tree<T>::Tree(const Tree<T>& t)
{
	if (t.m_left != nullptr)
	{
		m_left = new(Tree<T>);
		m_left = t.m_left;
	}
	else
	{
		m_left = nullptr;
	}

	if (t.m_right != nullptr)
	{
		m_right = new(Tree<T>);
		m_right = t.m_right;
	}
	else
	{
		m_right = nullptr;
	}
	//m_father: here m_father must be nullptr
	//we are creating a tree, if it has to be connected with another one you will use setRight o r left.
	m_father = nullptr;

	if (t.m_data != nullptr)
	{
		m_data = new(T);
		m_data = t.m_data;
	}
	else
	{
		m_data = nullptr;
	}
}

/////////////////////////////////////////////////////////////////////////////
// Tree(nomFitxer):                                                        //
//                 constructor que obre fitxer i crida a metode privat     //
// TreeRec(ifstream& fitxerNodes, int h, Tree<T>* father)              //
//            metode privat que llegeix arbre de forma recursiva           //
//Lectura d'un fitxer a on tindrem                                         //
//alcada                                                                   //
//estat: 0 o 1 segons sigui buit o amb informacio al costat dada           //
//Esta en preordre Preordre(FillEsq) Arrel Preordre(FillDret)                //
/////////////////////////////////////////////////////////////////////////////
template<typename T>
Tree<T>::Tree(string nomFitxer)
{
	ifstream fitxerNodes;

	fitxerNodes.open(nomFitxer.c_str());
	if (fitxerNodes.is_open())
	{
		//Llegim alçada arbre binari
		int h;
		fitxerNodes >> h;
		if (!fitxerNodes.eof())
		{
			int estat;
			fitxerNodes >> estat;
			if (estat == 1)
			{
				if (fitxerNodes.is_open())	TreeRec(fitxerNodes, h, nullptr);
			}
		}
		fitxerNodes.close();
	}
}

template<typename T>
void Tree<T>::TreeRec(ifstream& fitxerNodes, int h, Tree<T>* father)
{
	m_father = father;
	m_data = new(T);
	fitxerNodes >> (*m_data);
	if (h > 0)
	{
		int estat;
		if (!fitxerNodes.eof())
		{
			fitxerNodes >> estat;
			if (!fitxerNodes.eof())
			{
				if (estat == 1)
				{
					m_left = new(Tree<T>);
					m_left->TreeRec(fitxerNodes, h - 1, this);
				}
			}
		}
		if (!fitxerNodes.eof())
		{
			fitxerNodes >> estat;
			if (!fitxerNodes.eof())
			{
				if (estat == 1)
				{
					m_right = new(Tree<T>);
					m_right->TreeRec(fitxerNodes, h - 1, this);
				}
			}
		}
	}
}


template<typename T>
Tree<T>::~Tree()
{
	if (m_right != nullptr)
	{
		delete m_right;
	}

	if (m_left != nullptr)
	{
		delete m_left;
	}

	if (m_data != nullptr)
	{
		delete m_data;
	}

	m_father = nullptr;
}

//Suposem l'arbre ordenat amb valors menors a arrel a esquerra i valors majors a dreta
template<typename T>
bool Tree<T>::cerca(const T& val, Tree<T>* valTrobat)
{
	if (m_data != nullptr) {
		if ((*m_data) == val)
		{
			valTrobat = this;
			return true;
		}
		else if (*m_data > val) {
			if (m_left != nullptr) {
				return m_left->cerca(val, valTrobat);
			}
		}
		else {
			if (m_right != nullptr)
			{
				return m_right->cerca(val, valTrobat);
			}
		}
	}
	return false;
}


template<typename T>
void Tree<T>::mostraExpressioRec(std::string& s, std::string& sep)
{
	//TODO ESTUDIANTS
	if (m_data != nullptr)
	{
		if (m_left != nullptr)
		{
			m_left->mostraExpressioRec(s, sep);
		}
		cout << (*m_data) << sep;
		s = s + (*m_data) + sep;

		if (m_right != nullptr)
		{
			m_right->mostraExpressioRec(s, sep);
		}
	}
}

template<typename T>
void Tree<T>::mostraExpressioIter(std::string& s, std::string& sep)
{
	//TODO ESTUDIANTS
	stack<Tree<T>*> pila;
	Tree<T>* nAct = this;
	while (nAct != nullptr || !pila.empty())
	{
		while (nAct != nullptr)
		{
			pila.push(nAct);
			nAct = nAct->m_left;
		}
		nAct = pila.top();
		pila.pop();
		cout << (*nAct->m_data) << endl;
		s = s + (*nAct->m_data) + sep;
		nAct = nAct->m_right;
	}
}

template <typename T>
bool TryParse(string input, T& var)
{
	static const string ws(" \t\f\v\n\r");
	size_t pos = input.find_last_not_of(ws);
	if (pos != string::npos)
		input.erase(pos + 1);
	else input.clear();
	stringstream buffer(input);
	return buffer >> var && buffer.eof();
}

template<typename T>
float Tree<T>::avalua()
{
	//TODO ESTUDIANTS
	if (m_data != nullptr)
	{
		float op1, op2;
		if (m_left != nullptr)
			op1 = m_left->avalua();
		if (m_right != nullptr)
			op2 = m_right->avalua();

		float data;

		if (TryParse(*m_data, data)) return data;

		if ((*m_data) == "+") return (op1 + op2);
		if ((*m_data) == "-") return (op1 - op2);
		if ((*m_data) == "*") return (op1 * op2);
		if ((*m_data) == "/") return (op1 / op2);
		cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
	}
	return 0;
}




/////////////////////////////////////////////////////////////////////////////
// coutArbreRec():                                                         //
//         Metode privat cridat per operator<<                             //
//                       que escriu arbre per pantalla de forma recursiva  //
// |--arrel                                                                //
// |---->FillDret1                                                         //
// |------>FillDret2                                                       //
// |------>FillEsquerre2                                                   //
// |---->FillEsquerre1                                                     //
//alcada                                                                   //
//estat: 0 o 1 segons sigui buit o amb informacio al costat dada           //
//Esta en inordre Inordre(FillEsq) Arrel Inordre(FillDret)                 //
/////////////////////////////////////////////////////////////////////////////
template<typename T>
std::ostream& Tree<T>::coutArbreRec(int n, std::ostream& out) const
{
	if (isEmpty())
	{//Pintem arbre buit
		for (int i = 0; i < n; i++)
		{
			out << "|--";
		}
		out << "-->BUIT" << endl;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			out << "|--";
		}
		out << "|-->" << (*m_data) << endl;
		if (!isLeave())
		{
			if (m_left != nullptr)
			{
				m_left->coutArbreRec(n + 1, out);
			}
			else
			{
				for (int i = 0; i < n + 1; i++)
				{
					out << "|--";
				}
				out << "|-->BUIT" << endl;
			}
			if (m_right != nullptr)
			{
				m_right->coutArbreRec(n + 1, out);
			}
			else
			{
				for (int i = 0; i < n + 1; i++)
				{
					out << "|--";
				}
				out << "|-->BUIT" << endl;
			}
		}
	}
	return out;
}
