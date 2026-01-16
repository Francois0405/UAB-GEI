#pragma once
#include "PuntDeInteresBase.h"
#include "Util.h"
#include "pch.h"

class PuntDeInteresBotigaSolucio : public PuntDeInteresBase
{
private:
    std::string m_shop;
    std::string m_opening_hours;
    std::string m_wheelchair;

public:
    PuntDeInteresBotigaSolucio();
    PuntDeInteresBotigaSolucio(Coordinate coord, std::string name,
        std::string shop, std::string opening_hours,
        std::string wheelchair);

    unsigned int getColor() override;

    // Getters para los atributos adicionales
    std::string getShop() const;
    std::string getOpeningHours() const;
    std::string getWheelchair() const;
};