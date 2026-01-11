#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <class T>
class TreeRB{
public:

	TreeRB() :m_left(nullptr), m_right(nullptr), m_father(nullptr), m_data(nullptr), m_color(RED) {}
	TreeRB(string nomFitxer);
	TreeRB(const TreeRB<T>& t);
	~TreeRB();
	void setVal(const T& val) { if (m_data==nullptr) m_data = new T(); (*m_data) = val;};
	bool isLeave() const { return ((m_left == nullptr) && (m_right == nullptr)); }
	bool isEmpty() const { return (m_data == nullptr); }
	TreeRB<T>* getRight() const { return m_right; }
	TreeRB<T>* getLeft() const { return m_left; }
	T& getData() const { return (*m_data); }
	bool cerca(const T& val, TreeRB<T>*& valTrobat);
	TreeRB<T>* oncle() const;
	bool esFillDret() const;
	bool esFillEsq() const;
	friend std::ostream& operator<<(std::ostream& out, const TreeRB<T>& t)
	{
		t.coutArbreRec(0, out);
		return out;
	};

	void insert(T& val);

private:
	enum COLOR { RED, BLACK };
	TreeRB<T>* m_left;
	TreeRB<T>* m_right;
	TreeRB<T>* m_father;
	T* m_data;
	COLOR m_color;
	void swapColor(TreeRB<T>* pNod1, TreeRB<T>* pNod2);
	void swapRootContents(TreeRB<T>*& pOldRoot, TreeRB<T>*& pNewRoot);
	void rotaDreta(TreeRB<T>* pNodAct);
	void rotaEsq(TreeRB<T>*& pNodAct);
	void rota(TreeRB<T>* nouNode, TreeRB<T>* pPare, TreeRB<T>* pAvi);
	void arreglaREDRED(TreeRB<T>* nouNode);
	void TreeRBRec(ifstream& fitxerNodes, int h, TreeRB<T>* father);
	std::ostream& coutArbreRec(int n, std::ostream& out) const;
};




template<class T>
TreeRB<T>::TreeRB(const TreeRB<T>& t)
{
	m_color = t.m_color;

	if (t.m_left != nullptr)
	{
		m_left = new TreeRB<T>(*(t.m_left));
		m_left->m_father = this;
	}
	else
		m_left = nullptr;

	if (t.m_right != nullptr)
	{
		m_right = new TreeRB<T>(*(t.m_right));
		m_right->m_father = this;
	}
	else
		m_right = nullptr;
	
	//m_father: here m_father must be nullptr
	//we are creating a TreeRB, if it has to be connected with another one you will use setRight o r left.
	m_father = nullptr;

	if (t.m_data != nullptr)
		m_data = new T(*t.m_data);
	else
		m_data = nullptr;
}

template<class T>
bool TreeRB<T>::esFillDret() const
{
	if (m_father != nullptr)
		return this == m_father->m_right;
	else
		return false;
}

template<class T>
bool TreeRB<T>::esFillEsq() const
{
	if (m_father != nullptr)
		return this == m_father->m_left;
	else
		return false;
}

template<class T>
TreeRB<T>* TreeRB<T>::oncle() const
{
	if (m_father == nullptr)
	{
		return nullptr;
	}
	else
	{
		if (m_father->m_father == nullptr)
			return nullptr;
		else
		{
			if (m_father->esFillEsq())
			{
				//oncle es fill dret
				return m_father->m_father->m_right;
			}
			else
			{
				//oncle es fill esquerre
				return m_father->m_father->m_left;
			}
		}
	}
}

template<class T>
void TreeRB<T>::swapColor(TreeRB<T>* pNod1, TreeRB<T>* pNod2)
{
	COLOR c = pNod1->m_color;
	pNod1->m_color = pNod2->m_color;
	pNod2->m_color = c;
}

template<typename T>
void TreeRB<T>::swapRootContents(TreeRB<T>*& pOldRoot, TreeRB<T>*& pNewRoot) 
{
	//TODO S21
	TreeRB<T> aux;
	TreeRB<T>* pAux;

	pAux = pOldRoot;
	pOldRoot = pNewRoot;
	pNewRoot = pAux;

	aux = (*pOldRoot);
	(*pOldRoot) = (*pNewRoot);
	(*pNewRoot) = aux;

	if (pOldRoot->m_left)
		pOldRoot->m_left->m_father = pOldRoot;
	if (pOldRoot->m_right)
		pOldRoot->m_right->m_father = pOldRoot;
	if (pNewRoot->m_left)
		pNewRoot->m_left->m_father = pNewRoot;
	if (pNewRoot->m_right)
		pNewRoot->m_right->m_father = pNewRoot;

	pAux = nullptr;
	aux.m_left = nullptr;
	aux.m_right = nullptr;
	aux.m_father = nullptr;
	aux.m_data = nullptr;
}

template<typename T>
void TreeRB<T>::rotaEsq(TreeRB<T>*& pNodAct)
{
	//TODO S21
	TreeRB<T>* pFD = pNodAct->m_right;
	TreeRB<T>* pBesavi = pNodAct->m_father;

	if (pBesavi)
	{
		if (pNodAct->esFillDret())
			pBesavi->m_right = pFD;
		else
			pBesavi->m_left = pFD;
		pFD->m_father = pBesavi;
	}
	else
	{
		this->swapRootContents(pNodAct, pFD);
		pFD->m_father = nullptr;
	}

	pNodAct->m_right = pFD->m_left;
	if (pFD->m_left)
		pFD->m_left->m_father = pNodAct;

	pNodAct->m_father = pFD;
	pFD->m_left = pNodAct;
}

template<class T> void TreeRB<T>::rotaDreta(TreeRB<T>* pNodAct)
{
	//TODO S21
	TreeRB<T>* pFE = pNodAct->m_left;
	TreeRB<T>* pBesavi = pNodAct->m_father;

	if (pBesavi)
	{
		if (pNodAct->esFillDret())
			pBesavi->m_right = pFE;
		else
			pBesavi->m_left = pFE;
	
		pFE->m_father = pBesavi;
	}
	else
	{
		this->swapRootContents(pNodAct, pFE);
		pFE->m_father = nullptr;
	}

	pNodAct->m_left = pFE->m_right;
	if (pFE->m_right)
	{
		pFE->m_right->m_father = pNodAct;
	}

	pNodAct->m_father = pFE;
	pFE->m_right = pNodAct;
}

template<typename T>
void TreeRB<T>::rota(TreeRB<T>* nouNode, TreeRB<T>* pPare, TreeRB<T>* pAvi)
{
	//TODO S21
	if (pPare->esFillEsq())
	{
		if (nouNode->esFillDret()) {//Esquerre-dret
			rotaEsq(pPare);
			pPare = pPare->m_father;
		}
		//Per esquerre-esquerre i esquerre-dret
		swapColor(pPare, pAvi);
		rotaDreta(pAvi);
	}
	else
	{//Per rotacions Dret-Dret i Dret-Esquerre, el pare es dret
		if (nouNode->esFillEsq()) { //Dret-esquerre
			rotaDreta(pPare);
			pPare = pPare->m_father;
		}//dret-dret i dret-esquerre
		swapColor(pPare, pAvi);
		rotaEsq(pAvi);
	}
}

template<class T>
void TreeRB<T>::arreglaREDRED(TreeRB<T>* nouNode)
{
	if (nouNode->m_father == nullptr)
	{
		//Es arrel
		nouNode->m_color = BLACK;
	}
	else
	{
		//Mirem pare, avi i oncle
		TreeRB<T>* pPare = nouNode->m_father;
		TreeRB<T>* pAvi = nouNode->m_father->m_father;
		TreeRB<T>* pOncle = nouNode->oncle();
		if (pPare->m_color != BLACK)
		{
			//Si el pare es BLACK ja hem acabat
			if ((pOncle!=nullptr)&&(pOncle->m_color == RED))
				{
					pPare->m_color = BLACK;
					pOncle->m_color = BLACK;
					pAvi->m_color = RED;
					arreglaREDRED(pAvi);
				}
			else { rota(nouNode, pPare, pAvi); }
		}
	}
}

template<class T>
void TreeRB<T>::insert(T& val)
{
	if (m_data == nullptr)
	{
		//Arbre buit
		m_data = new T;
		(*m_data) = val;
		m_color = BLACK;
	}
	else
	{
		TreeRB<T>* ptAux=nullptr;
		bool trobat = cerca(val, ptAux);
		if (!trobat)
		{
			//Si trobem valor no fem res; si no el trobem
			//Creem un node RED amb valor val fill de ptAux
			TreeRB<T>* nouNode = new TreeRB<T>;
			nouNode->m_data = new T;
			(*nouNode->m_data) = val;
			nouNode->m_father = ptAux;

			if (val < (*ptAux->m_data))
			{
				//El nou valor sera fillEsq de ptAux
				ptAux->m_left= nouNode;
			}
			else
			{
				//El nou valor sera fillDret de ptAux
				ptAux->m_right= nouNode;
			}

			arreglaREDRED(nouNode);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// TreeRB(nomFitxer):                                                        //
//                 constructor que obre fitxer i crida a metode privat     //
// TreeRBRec(ifstream& fitxerNodes, int h, TreeRB<T>* father)              //
//            metode privat que llegeix arbre de forma recursiva           //
//Lectura d'un fitxer a on tindrem                                         //
//alcada                                                                   //
//estat: 0 o 1 segons sigui buit o amb informacio al costat dada           //
//Esta en preordre Preordre(FillEsq) Arrel Preordre(FillDret)                //
/////////////////////////////////////////////////////////////////////////////
template<class T>
TreeRB<T>::TreeRB(string nomFitxer)
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
				if (fitxerNodes.is_open())	TreeRBRec(fitxerNodes, h, nullptr);
			}
		}
		fitxerNodes.close();
	}
}

template<class T>
void TreeRB<T>::TreeRBRec(ifstream& fitxerNodes, int h, TreeRB<T>* father)
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
					m_left = new(TreeRB<T>);
					m_left->TreeRBRec(fitxerNodes, h - 1, this);
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
					m_right = new(TreeRB<T>);
					m_right->TreeRBRec(fitxerNodes, h - 1, this);
				}
			}
		}
	}
}


template<class T>
TreeRB<T>::~TreeRB()
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
template<class T>
bool TreeRB<T>::cerca(const T& val, TreeRB<T>*& valTrobat) 
{
	bool trobat = false;
	if (m_data != nullptr)
	{
		if (val == (*m_data))
		{
			trobat = true;
			valTrobat = this;
		}
		else
			if (val < (*m_data))
			{
				if (m_left != nullptr)
				{
					trobat = m_left->cerca(val, valTrobat);
				}
				else
					valTrobat = this;
			}
			else
			{
				if (m_right != nullptr)
				{
					trobat = (m_right->cerca(val, valTrobat));
				}
				else
					valTrobat = this;
			}		
	}
	return trobat;
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
template<class T>
std::ostream& TreeRB<T>::coutArbreRec(int n, std::ostream& out) const
{
	if (isEmpty())
	{//Pintem arbre buit
		out << "Comment :=>> ";
		for (int i = 0; i < n; i++)
		{
			out << "|--";
		}
		out << "-->BUIT" << endl;
	}
	else
	{
		out << "Comment :=>> ";
		for (int i = 0; i < n; i++)
		{
			out << "|--";
		}
		out << "|-->";
		if (m_color == RED)
			out << "RED,";
		else
			out << "BLACK,"; 
		out << (*m_data) << endl;
		if (!isLeave())
		{
			if (m_left != nullptr)
			{
				m_left->coutArbreRec(n + 1,out);
			}
			else
			{
				out << "Comment :=>> ";
				for (int i = 0; i < n + 1; i++)
				{
					out << "|--";
				}
				out << "|-->BUIT" << endl;
			}
			if (m_right != nullptr)
			{
				m_right->coutArbreRec(n + 1,out);
			}
			else
			{
				out << "Comment :=>> ";
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