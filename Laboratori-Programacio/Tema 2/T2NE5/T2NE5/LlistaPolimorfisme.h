#pragma once
#include <iostream>
#include <list>

using namespace std;

template <typename ClassB>
class LlistaPolimorfisme
{
public:
	LlistaPolimorfisme() {}
	LlistaPolimorfisme(const LlistaPolimorfisme& l)
	{
		for (auto it : l.m_llista)
		{
			if (it) {
				m_llista.push_back(new ClassB(*it));
			} else {
				m_llista.push_back(nullptr);
			}
		}
	}
	~LlistaPolimorfisme() {
		for (auto ptr : m_llista)
			delete ptr;
	}

	LlistaPolimorfisme& operator=(const LlistaPolimorfisme& l)
	{
		if (this != &l)
		{
			m_llista.clear();
			for (auto it : l.m_llista)
			{
				if (it) {
					m_llista.push_back(it->clone());
				} else {
					m_llista.push_back(nullptr);
				}
			}
		}
		return *this;
	}

	void afegeixElement(ClassB* element)
	{
		m_llista.push_back(element->clone());
	}

	bool eliminaElement(const string& codi, ClassB*& element) )
	{
		
	}

private:
	list<ClassB*> m_llista;
};