#pragma once
#include "Punt.h"

// Ax + By + C
class Recta
{
public:
	Recta() : m_a(0), m_b(0), m_c(0) {}
	Recta(float a, float b, float c);
	Recta(const Punt& pt1, const Punt& pt2);

	void setA(float A) { m_a = A; }
	void setB(float B) { m_b = B; }
	void setC(float C) { m_c = C; }
	float getA() const { return m_a; }
	float getB() const { return m_b; }
	float getC() const { return m_c; }

	// Ax + By − 1 = 0
	void formaCanonica();
	bool paralela(const Recta& r) const;
	float operator-(const Punt& pt) const;
	bool operator==(const Recta& r) const;
private:
	Punt m_pt1;
	Punt m_pt2;
	float m_a;
	float m_b;
	float m_c;
};

