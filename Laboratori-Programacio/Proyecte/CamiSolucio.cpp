#include "pch.h"
#include "CamiSolucio.h"

std::vector<Coordinate> CamiSolucio::getCamiCoords()
{
    //El enunciado pide crear estas corrd preterminadas
    // Se tiene que cambiar Tasca4
    return m_coords;
}

void CamiSolucio::afegeixCoordinate(const Coordinate& coord)
{
    m_coords.push_back(coord);
}