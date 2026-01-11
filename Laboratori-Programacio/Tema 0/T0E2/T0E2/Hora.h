#pragma once
 
class Hora
{
public:
	Hora() : m_hora(0), m_minut(0), m_segon(0) {};
	Hora(const int hora, const int minut,const int segon) : m_hora(hora), m_minut(minut), m_segon(segon) {};
	Hora(const Hora& hora) : m_hora(hora.m_hora), m_minut(hora.m_minut), m_segon(hora.m_segon) {};

	void setHora(int const hora) { m_hora = hora; }
	void setMinuts(int const minut) { m_minut = minut; }
	void setSegons(int const segon) { m_segon = segon; }
	int getHora() const { return m_hora; }
	int getMinuts() const { return m_minut; }
	int getSegons() const { return m_segon; }

	bool horaValida();
	int toSegons();

	Hora operator+(int segons) const;
	Hora operator+(const Hora& hora) const;
	bool operator==(Hora hora);
	bool operator<(Hora hora);
	Hora operator=(Hora hora);
private:
	int m_hora;
	int m_minut;
	int m_segon;
};
