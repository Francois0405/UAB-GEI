#include "pch.h"
#include "MapaSolucio.h"
#include "GrafSolucio.h"


MapaSolucio::MapaSolucio()
{

}

MapaSolucio::~MapaSolucio()
{
    // Liberar memoria de los punteros 

    // Para puntos de interés
    for (int i = 0; i < m_pdis.size(); i++) {
        delete m_pdis[i];
    }

    // Para caminos
    for (int i = 0; i < m_camins.size(); i++) {
        delete m_camins[i];
    }
}

void MapaSolucio::getPdis(std::vector<PuntDeInteresBase*>& pdis)
{
    // Tarea 5: Retornar dos puntos de interés de ejemplo
    for (int i = 0; i < m_pdis.size(); i++)
    {
        pdis.push_back(m_pdis[i]);
    }
}

void MapaSolucio::getCamins(std::vector<CamiBase*>& camins) 
{
    // Tarea 6: Retornar el camino de ejemplo de la Tarea 4
    for (int i = 0; i < m_camins.size(); i++)
    {
        camins.push_back(m_camins[i]);
    }
}

void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements)
{
    // Tarea 7-9 procesar los elementos XML     

    m_pdis.clear();//limpiar para evitar inconsistencias los puntos de interes
    m_camins.clear();
    std::vector <Coordinate> coordenadesCami;
    bool emmagatzemar = false;
    for (int i = 0; i < xmlElements.size(); i++)
    {
        if (xmlElements[i].id_element == "node") // Pdi
        {
            std::string name, shop, opening_hours, cuisine, wheelchair;
            Coordinate coord = { 0.0, 0.0 };
            bool puntDeInteres = false;

            // llegir atributs
            for (int j = 0; j < xmlElements[i].atributs.size(); j++)
            {
                if (xmlElements[i].atributs[j].first == "lat")
                    coord.lat = std::stod(xmlElements[i].atributs[j].second);
                else if (xmlElements[i].atributs[j].first == "lon")
                    coord.lon = std::stod(xmlElements[i].atributs[j].second);
            }
            //llegir fills
            for (int j = 0; j < xmlElements[i].fills.size(); j++)
            {
                if (xmlElements[i].fills[j].first == "tag")
                {
                    // Emmagatzemem el valor d’aquest tag
                    std::pair<std::string, std::string> valorTag =
                        Util::kvDeTag(xmlElements[i].fills[j].second);
                    // Comprovem que es el tag que busquem
                    if (valorTag.first == "name")
                    {
                        name = valorTag.second;
                        puntDeInteres = true;
                    }
                    else if (valorTag.first == "highway" || valorTag.first == "public_transport" ||
                        valorTag.first == "access" || valorTag.first == "entrance")
                    {
                        puntDeInteres = false;
                        break;  //Si es node camí no necessitem cap altra infomació i sortim del bucle
                    }
                    else if (valorTag.first == "shop")
                        shop = valorTag.second;
                    else if (valorTag.first == "opening_hours")
                        opening_hours = valorTag.second;
                    else if (valorTag.first == "cuisine")
                        cuisine = valorTag.second;
                    else if (valorTag.first == "wheelchair")
                        wheelchair = valorTag.second;
                }
            }

            // tipus de punt d'interes
            if (!shop.empty() && puntDeInteres)
            {
                // Es una botiga
                m_pdis.push_back(new PuntDeInteresBotigaSolucio(coord, name, shop, opening_hours, wheelchair));
            }
            else if (!cuisine.empty() && puntDeInteres)
            {
                // Es un restaurant
                m_pdis.push_back(new PuntDeInteresRestaurantSolucio(coord, name, cuisine, wheelchair));
            }
            else if (puntDeInteres)
            {
                // sino, pdi generic
                m_pdis.push_back(new PuntDeInteresBase(coord, name));
            }
        }
        else if (xmlElements[i].id_element == "way") // Cami
        {
            coordenadesCami.clear();
            emmagatzemar = false;

            //trobar ids dels nodes
            for (int j = 0; j < xmlElements[i].fills.size(); j++)
            {
                if (xmlElements[i].fills[j].first == "nd")
                {

                    std::string id;
                    Coordinate coord = { 0.0,0.0 };
                    for (int k = 0; k < xmlElements[i].fills[j].second.size(); k++) //cambiar
                    {
                        if (xmlElements[i].fills[j].second[k].first == "ref")
                        {
                            //buscar lat y lon del nodo con id = xmlElements[i].fills[j].second[k].second 
                            id = xmlElements[i].fills[j].second[k].second;
                            break;
                        }
                    }

                    coord = buscarCoordIdNode(xmlElements, id);
                    if (coord.lat != 0.0 && coord.lon != 0.0)
                        coordenadesCami.push_back(coord);
                }

                else if (xmlElements[i].fills[j].first == "tag")
                {
                    // Emmagatzemem el valor d’aquest tag
                    std::pair<std::string, std::string> valorTag =
                        Util::kvDeTag(xmlElements[i].fills[j].second);
                    // Comprovem que es el tag que busquem
                    if (valorTag.first == "highway")
                    {
                        emmagatzemar = true;
                    }
                }
            }

            if (emmagatzemar)
            {
                m_camins.push_back(new CamiSolucio(coordenadesCami));
            }
        }
    }
}

Coordinate MapaSolucio::buscarCoordIdNode(std::vector<XmlElement>& xmlElements, const std::string& id)
{
    Coordinate coord = { 0.0, 0.0 };
    bool guardar = false;
    for (int i = 0; i < xmlElements.size() && !guardar; i++)
    {
        if (xmlElements[i].id_element == "node")
        {
            for (int j = 0; j < xmlElements[i].atributs.size(); j++)
            {
                if (xmlElements[i].atributs[j].first == "id")
                {
                    if (xmlElements[i].atributs[j].second == id)
                        guardar = true;
                }
                else if (xmlElements[i].atributs[j].first == "lat")
                    coord.lat = std::stod(xmlElements[i].atributs[j].second);
                else if (xmlElements[i].atributs[j].first == "lon")
                    coord.lon = std::stod(xmlElements[i].atributs[j].second);
            }
        }
    }
    if (!guardar)
        coord = { 0.0, 0.0 };
    return coord;
}

CamiBase* MapaSolucio::buscaCamiMesCurt(PuntDeInteresBase* desde, PuntDeInteresBase* a) {
    // TODO IMPLEMENTACIO DE LA SEGONA PART
    CamiSolucio* camiMesCurt = new CamiSolucio();
    GrafSolucio graf(*this);
    BallTree arbre;
    arbre.construirArbre(graf.getNodes());
    Coordinate coordDesde = desde->getCoord();
    Coordinate coordA = a->getCoord();

    Coordinate zero = { 0.0, 0.0 };
    Coordinate nodeIni = arbre.nodeMesProper(coordDesde, zero, &arbre);
    Coordinate nodeFi = arbre.nodeMesProper(coordA, zero, &arbre);

    // Djisktra
    stack<Coordinate> camiStack;
    graf.camiMesCurt(nodeIni, nodeFi, camiStack);

    while (!camiStack.empty())
    {
        camiMesCurt->afegeixCoordinate(camiStack.top());
		camiStack.pop();
    }

    return camiMesCurt;
}

