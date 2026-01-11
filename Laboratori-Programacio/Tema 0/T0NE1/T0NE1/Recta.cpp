#include "Recta.h"
#include <cmath>

Recta::Recta(float a, float b, float c) 
{
	m_a = a;
	m_b = b;
	m_c = c;
	float x = 0;
	float y = (-m_a * x - m_c) / m_b;
	m_pt1.setX(x);
	m_pt1.setY(y);
}

Recta::Recta(const Punt& pt1, const Punt& pt2) 
{
	m_pt1 = pt1;
	m_pt2 = pt2;
	if (pt2.getX() - pt1.getX() == 0)
	{
		m_a = 1;
		m_b = 0;
		m_c = -pt1.getX();
	}
	else
	{
		m_a = (pt2.getY() - pt1.getY()) / (pt2.getX() - pt1.getX());
		m_b = -1;
		m_c = (-m_a * pt1.getX()) + pt1.getY();
	}
};

void Recta::formaCanonica()
{
	if (m_c != 0)
	{
		float divisor;
		divisor = -m_c;
		m_a = m_a / divisor;
		m_b = m_b / divisor;
		m_c = m_c / divisor;
		if (m_c != -1)
			throw runtime_error("DA FUCK??");
	}
}

float Recta::operator-(const Punt& pt) const
{
	if (sqrt(pow(m_a, 2) + pow(m_b, 2)) == 0)
		return -1;
	return ((abs(m_a * pt.getX() + m_b * pt.getY() + m_c) / sqrt(pow(m_a, 2) + pow(m_b, 2))));
}

bool Recta::paralela(const Recta& r) const
{
	if (m_a * r.m_b == r.m_a * m_b)
		return true;
	return false;
}

bool Recta::operator==(const Recta& r) const
{
	if ((m_a * r.m_b == r.m_a * m_b) && (m_a * r.m_c == r.m_a * m_c) && (m_b * r.m_c == r.m_b * m_c))
		return true;
	return false;
}