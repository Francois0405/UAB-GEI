#include "pch.h"
#include "PuntDeInteresRestaurantSolucio.h"

PuntDeInteresRestaurantSolucio::PuntDeInteresRestaurantSolucio()
    : PuntDeInteresBase(), m_cuisine(""), m_wheelchair("")
{
}

PuntDeInteresRestaurantSolucio::PuntDeInteresRestaurantSolucio(Coordinate coord, std::string name,
    std::string cuisine, std::string wheelchair)
    : PuntDeInteresBase(coord, name), m_cuisine(cuisine), m_wheelchair(wheelchair)
{
}

unsigned int PuntDeInteresRestaurantSolucio::getColor()
{
    if (m_cuisine == "pizza" && m_wheelchair == "yes") {
        return 0x7FFFD4;  // Aquamarina
    }
    else if (m_cuisine == "chinese") {
        return 0x00FFFF;  // Cian
    }
    else if (m_wheelchair == "yes") {
        return 0x5D3FD3;  // Violeta
    }
    else {
        return PuntDeInteresBase::getColor();  // Color por defecto de la clase base (0xFFA500 - naranja)
    }
}

std::string PuntDeInteresRestaurantSolucio::getCuisine() const
{
    return m_cuisine;
}

std::string PuntDeInteresRestaurantSolucio::getWheelchair() const
{
    return m_wheelchair;
}