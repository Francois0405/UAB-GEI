#include "Hora.h"

bool Hora::horaValida()
{
	return (!(m_hora > 23 || m_hora < 0 || m_minut < 0 || m_minut > 59 || m_segon < 0 || m_segon > 59));
}

int Hora::toSegons()
{
	int segons = m_segon;
	segons += m_minut * 60;
	segons += m_hora * 3600;
	return segons;
}

Hora Hora::operator+(int segons) const
{
	Hora res = *this;
	res.m_segon += segons;

	while (res.m_segon > 59)
	{
		res.m_segon -= 60;
		res.m_minut++;
		if (res.m_minut > 59)
		{
			res.m_minut = 0;
			res.m_hora++;
			if (res.m_hora > 23)
			{
				res.m_hora = 0;
			}
		}
	}
	return res;
}

Hora Hora::operator+(const Hora& hora) const
{
	Hora res = *this;
	res.m_hora += hora.m_hora;
	res.m_minut += hora.m_minut;
	res.m_segon += hora.m_segon;

	while (res.m_segon > 59)
	{
		res.m_segon -= 60;
		res.m_minut++;
		while (res.m_minut > 59)
		{
			res.m_minut -= 60;
			res.m_hora++;
			while (res.m_hora > 23)
			{
				res.m_hora -= 24;
			}
		}
	}
	return res;
}

bool Hora::operator==(Hora hora)
{
	return (m_hora == hora.m_hora && m_minut == hora.m_minut && m_segon == hora.m_segon);
}

bool Hora::operator<(Hora hora)
{
	bool res;
	if (m_hora < hora.m_hora)
		res = true;
	else if (m_hora > hora.m_hora)
		res = false;
	else
	{
		if (m_minut < hora.m_minut)
			res = true;
		else if (m_minut > hora.m_minut)
			res = false;
		else
		{
			if (m_segon < hora.m_segon)
				res = true;
			else
				res = false;
		}
	}
	return res;
}

Hora Hora::operator=(Hora hora)
{
	m_hora = hora.m_hora;
	m_minut = hora.m_minut;
	m_segon = hora.m_segon;
	return *this;
}