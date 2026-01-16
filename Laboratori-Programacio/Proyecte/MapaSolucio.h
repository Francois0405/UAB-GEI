#pragma once
#include "pch.h"
#include "MapaBase.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include "CamiSolucio.h"
#include "Util.h"

#include "BallTree.h"
#include <vector>

class GrafSolucio;
class MapaSolucio : public MapaBase
{
private:
    std::vector<PuntDeInteresBase*> m_pdis;
    std::vector<CamiBase*> m_camins;

public:
    MapaSolucio();
    ~MapaSolucio();

    void getPdis(std::vector<PuntDeInteresBase*>& pdis) override;
    void getCamins(std::vector<CamiBase*>& camins) override;
    void parsejaXmlElements(std::vector<XmlElement>& xmlElements) override;
    CamiBase* buscaCamiMesCurt(PuntDeInteresBase* desde, PuntDeInteresBase* a);

    // Métodos auxiliares para añadir elementos
    Coordinate buscarCoordIdNode(std::vector<XmlElement>& xmlElements, const std::string& id);
};