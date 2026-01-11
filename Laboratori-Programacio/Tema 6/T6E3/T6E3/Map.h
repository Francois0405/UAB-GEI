#pragma once
#include <stdlib.h>
#include <iostream>
#include <utility>
#include "TreeRB.hpp"
using namespace std;



template<class TClau, class TValor>
class PairMap
{
public:
	TClau first;
	TValor second;
	PairMap() { first = TClau(); second = TValor(); }
	PairMap(TClau primer, TValor segon) { first = primer; second = segon; }
	bool operator<(PairMap<TClau, TValor> valor) const { return (first < valor.first); }
	bool operator==(PairMap<TClau, TValor> valor) const {	return (first == valor.first); }
	friend ostream& operator<<(ostream& out, PairMap<TClau, TValor> valor)
	{
		out << "<" << valor.first << ", " << valor.second << ">";
		return out;
	}
};



template<class TClau, class TValor>
class Map
{
public:
	Map();
	Map(const Map<TClau, TValor>& m);
	~Map();
	bool esBuit() const;
	TValor& operator[](const TClau& clau);
	void afegeix(const TClau& clau, const TValor& valor);
	friend std::ostream& operator<<(std::ostream& out, const Map<TClau, TValor>& m)
	{
		out << m.m_map;
		return out;
	}
private:
	// PER COMPLETAR
	TreeRB<PairMap<TClau, TValor>> m_map;
	TValor m_valorDefecte;
};


// IMPLEMENTACI� M�TODES PER COMPLETAR
template<class TClau, class TValor>
Map<TClau, TValor>::Map() : m_map(), m_valorDefecte(TValor()) {}


template<class TClau, class TValor>
Map<TClau, TValor>::Map(const Map<TClau, TValor>& m)
{
	m_map = m.m_map;
	m_valorDefecte = m.m_valorDefecte;
}

template<class TClau, class TValor>
Map<TClau, TValor>::~Map()
{

}

template<class TClau, class TValor>
bool Map<TClau, TValor>::esBuit() const
{
	return m_map.isEmpty();
}

template<class TClau, class TValor>
TValor& Map<TClau, TValor>::operator[](const TClau& clau)
{
	PairMap<TClau, TValor> cercat(clau, TValor());
	TreeRB<PairMap<TClau, TValor>>* node;

	if (m_map.cerca(cercat, node))
	{
		return node->getData().second;
	}
	else
	{
		m_valorDefecte = TValor();
		return m_valorDefecte;
	}
}

template<class TClau, class TValor>
void Map<TClau, TValor>::afegeix(const TClau& clau, const TValor& valor)
{
	PairMap<TClau, TValor> nou(clau, valor);
	TreeRB<PairMap<TClau, TValor>>* node;

	if (m_map.cerca(nou, node))
	{
		// Ja existeix → actualitzem valor
		node->getData().second = valor;
	}
	else
	{
		// No existeix → inserim
		m_map.insert(nou);
	}
}
