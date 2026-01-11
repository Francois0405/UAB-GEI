#include "Matriu.h"
#include <cmath>

Matriu::~Matriu()
{
	for (int i = 0; i < m_nFiles; i++)
		delete[] m_matriu[i];
	delete[] m_matriu;
}

void Matriu::resize(int nFiles, int nColumnes)
{
	if (m_nFiles == nFiles && m_nColumnes == nColumnes)
		return;
	if (nFiles < 0 || nColumnes < 0)
		return;
	/*if (nFiles == 0 || nColumnes == 0)
	{
		for (int i = 0; i < m_nFiles; i++)
			delete[] m_matriu[i];
		delete[] m_matriu;
		m_matriu = nullptr;
		m_nColumnes = nColumnes;
		m_nFiles = nFiles;
		return;
	}*/

	// Alocamos memoria
	float** newMat = nullptr;
	newMat = new float*[nFiles];
	for (int i = 0; i < nFiles; i++)
	{
		newMat[i] = new float[nColumnes];
	}
	
	for (int i = 0; i < nFiles; i++)
	{
		for (int j = 0; j < nColumnes; j++)
		{
			if (j < m_nColumnes && i < m_nFiles)
			{
				newMat[i][j] = m_matriu[i][j];
			}
			else
			{
				newMat[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < m_nFiles; i++)
		delete[] m_matriu[i];
	delete[] m_matriu;
	m_matriu = newMat;
	m_nColumnes = nColumnes;
	m_nFiles = nFiles;
}

void Matriu::transpose()
{
	if (m_nColumnes <= 0 || m_nFiles <= 0)
	{
		return;
	}
	Matriu m(m_nColumnes, m_nFiles);

	for (int i = 0; i < m_nFiles; i++)
	{
		for (int j = 0; j < m_nColumnes; j++)
		{
			if (i != j)
			{
				m.m_matriu[j][i] = m_matriu[i][j];
			}
			else
			{
				m.m_matriu[i][j] = m_matriu[i][j];
			}
		}
	}
	*this = m;
}

Matriu& Matriu::operator=(const Matriu& m)
{
	if (this == &m) 
	{
		return *this;
	}

	if (m_matriu != nullptr)
	{
		// Alliberem todes les files y despres el array de punters
		for (int i = 0; i < m_nFiles; i++)
			delete[] m_matriu[i];
		delete[] m_matriu;
		m_matriu = nullptr;
	}

	m_nColumnes = m.m_nColumnes;
	m_nFiles = m.m_nFiles;

	if (m_nFiles > 0 && m_nColumnes > 0)
	{
		m_matriu = new float*[m_nFiles];

		for (int i = 0; i < m_nFiles; i++)
		{
			m_matriu[i] = new float[m_nColumnes];
			for (int j = 0; j < m_nColumnes; j++)
			{
				m_matriu[i][j] = m.m_matriu[i][j];
			}
		}
	}
	else
	{
		m_matriu = nullptr;
		m_nColumnes = 0;
		m_nFiles = 0;
	}
	return *this;
}

void Matriu::initValor(float valor)
{
	for (int i = 0; i < m_nFiles; i++)
	{
		for (int j = 0; j < m_nColumnes; j++)
		{
			m_matriu[i][j] = valor;
		}
	}
}

void Matriu::setValor(int fila, int columna, float valor)
{
	m_matriu[fila][columna] = valor;
}

float Matriu::getValor(int fila, int columna) const
{
	return (m_matriu[fila][columna]);
}

Matriu Matriu::operator+(const Matriu& m)
{
	Matriu res2;
	if (m_nColumnes != m.m_nColumnes && m_nFiles != m.m_nFiles)
		return res2;
	Matriu res(m_nFiles, m_nColumnes);
	for (int i = 0; i < m_nFiles; i++)
	{
		for (int j = 0; j < m_nColumnes; j++)
		{
			res.m_matriu[i][j] = m_matriu[i][j] + m.m_matriu[i][j];
		}
	}
	return res;
}

Matriu Matriu::operator+(float s)
{
	Matriu res(m_nFiles, m_nColumnes);

	for (int i = 0; i < m_nFiles; i++)
	{
		for (int j = 0; j < m_nColumnes; j++)
		{
			res.m_matriu[i][j] = m_matriu[i][j] + s;
		}
	}
	return res;
}

bool Matriu::operator==(const Matriu& m)
{
	bool res = true;

	int i = 0;
	int j;
	while (i < m_nFiles && res)
	{
		j = 0;
		while (j < m_nColumnes && res)
		{
			if (m_matriu[i][j] != m.m_matriu[i][j])
				res = false;
			j++;
		}
		i++;
	}
	return res;
}

#include <iostream>
using namespace std;
void Matriu::printMatriu()
{
	for (int i = 0; i < m_nFiles; i++)
	{
		for (int j = 0; j < m_nColumnes; j++)
		{
			cout << m_matriu[i][j] << " ";
		}
		cout << endl;
	}
}