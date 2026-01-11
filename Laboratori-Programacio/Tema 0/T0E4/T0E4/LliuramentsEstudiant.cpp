#include "LliuramentsEstudiant.h"

void LliuramentsEstudiant::afegeixTramesa(const string& fitxer, const string& data)
{
	Tramesa novaTramesa(fitxer, data);
	m_trameses.push_front(novaTramesa);
}

bool LliuramentsEstudiant::consultaTramesa(const string& data, string& fitxer)
{
	Tramesa toFind(fitxer, data);
	for (const Tramesa it : m_trameses)
	{
		if (it.getData() == toFind.getData())
		{
			fitxer = it.getFitxer();
			return true;
		}
	}
	return false;
}

bool LliuramentsEstudiant::eliminaTramesa(const string& data)
{
	bool trobat = false;
	forward_list<Tramesa>::iterator	it = m_trameses.begin();
	forward_list<Tramesa>::iterator	before_it = m_trameses.before_begin();
	while (!trobat && it != m_trameses.end())
	{
		if (it->getData() == data)
		{
			m_trameses.erase_after(before_it);
			trobat = true;
		}
		else
		{
			it++;
			before_it++;
		}
	}
	return trobat;
}