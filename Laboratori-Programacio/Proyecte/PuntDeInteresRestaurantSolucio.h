#pragma once
#include "PuntDeInteresBase.h"
#include "pch.h"

class PuntDeInteresRestaurantSolucio : public PuntDeInteresBase
{
private:
    std::string m_cuisine;
    std::string m_wheelchair;

public:
    PuntDeInteresRestaurantSolucio();
    PuntDeInteresRestaurantSolucio(Coordinate coord, std::string name,
        std::string cuisine, std::string wheelchair);

    unsigned int getColor() override;

    // Getters para los atributos adicionales
    std::string getCuisine() const;
    std::string getWheelchair() const;
};