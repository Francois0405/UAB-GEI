#include "pch.h"
#include "PuntDeInteresBotigaSolucio.h"

PuntDeInteresBotigaSolucio::PuntDeInteresBotigaSolucio()
    : PuntDeInteresBase(), m_shop(""), m_opening_hours(""), m_wheelchair("")
{
}

PuntDeInteresBotigaSolucio::PuntDeInteresBotigaSolucio(Coordinate coord, std::string name,
    std::string shop, std::string opening_hours,
    std::string wheelchair)
    : PuntDeInteresBase(coord, name), m_shop(shop), m_opening_hours(opening_hours), m_wheelchair(wheelchair)
{
}

unsigned int PuntDeInteresBotigaSolucio::getColor()
{
    if (m_shop == "supermarket") {
        return 0xDFFF00;  // Verde amarillo
    }
    else if (m_shop == "tobacco") {
        return 0xFF7F50;  // Coral
    }
    else if (m_shop == "bakery") {
        // Verificar si tiene horario 06:00-22:00 y acceso movilidad reducida
        if (m_opening_hours.find("06:00-22:00") != std::string::npos &&
            m_wheelchair == "yes") {
            return 0x4CBB17;  // Verde
        }
        return 0xFA8072;  // Salmon
    }
    else {
        return 0xFFEA00;  // Amarillo para otros shops
    }
}

std::string PuntDeInteresBotigaSolucio::getShop() const
{
    return m_shop;
}

std::string PuntDeInteresBotigaSolucio::getOpeningHours() const
{
    return m_opening_hours;
}

std::string PuntDeInteresBotigaSolucio::getWheelchair() const
{
    return m_wheelchair;
}