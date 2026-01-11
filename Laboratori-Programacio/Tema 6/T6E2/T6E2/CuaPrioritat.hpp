#pragma once
#include "Heap.hpp"

template <class T>
class CuaPrioritat
{
public:
	CuaPrioritat() {}
	~CuaPrioritat() {}
	CuaPrioritat(const CuaPrioritat<T>& cua);
	CuaPrioritat& operator=(const CuaPrioritat<T>& cua);

	bool esBuida() const;
	int getNElements() const;
	T& top();
	void push(const T& element);
	void pop();
	void remove(const T& element);
private:
	// PER COMPLETAR
	Heap<T> m_heap;

};


// IMPLEMENTACIO METODES PER COMPLETAR
template <class T>
CuaPrioritat<T>::CuaPrioritat(const CuaPrioritat<T>& cua)
{
	m_heap = cua.m_heap;
}

template <class T>
CuaPrioritat<T>& CuaPrioritat<T>::operator=(const CuaPrioritat<T>& cua)
{
	if (this != &cua)
	{
		m_heap = cua.m_heap;
	}
	return *this;
}

template <class T>
bool CuaPrioritat<T>::esBuida() const
{
	return getNElements() == 0;
}

template <class T>
int CuaPrioritat<T>::getNElements() const
{
	return m_heap.getMida() + 1;
}

template <class T>
T& CuaPrioritat<T>::top()
{
	return m_heap.getMinim();
}

template <class T>
void CuaPrioritat<T>::push(const T& element)
{
	m_heap.insereix(element);
}

template <class T>
void CuaPrioritat<T>::pop()
{
	m_heap.esborraMinim();
}

template <class T>
void CuaPrioritat<T>::remove(const T& element)
{
	m_heap.esborra(element);
}