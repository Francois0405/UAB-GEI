#pragma once
#include "pch.h"
#include "CamiBase.h"
#include <vector>

class CamiSolucio :public CamiBase
{

public:
	CamiSolucio() {}
	CamiSolucio(const std::vector<Coordinate>& coords) : m_coords(coords) {}

	std::vector<Coordinate> getCamiCoords() override;

	void afegeixCoordinate(const Coordinate& coord);

private:
	std::vector<Coordinate>m_coords;
};