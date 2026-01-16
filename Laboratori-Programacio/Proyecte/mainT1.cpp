#include "pch.h"
#include "GrafSolucio.h"
#include "MapaSolucio.h"
#include "CamiSolucio.h"
#include "PuntDeInteresBase.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include "Util.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Función para visualizar matriz de forma clara
void visualizarMatriz(const vector<vector<double>>& matAdj, const vector<Coordinate>& nodes) {
    cout << "\n=== VISUALIZACIÓN MATRIZ ===" << endl;
    cout << "Nodos: ";
    for (size_t i = 0; i < nodes.size(); i++) {
        cout << "N" << i << "(" << nodes[i].lat << "," << nodes[i].lon << ") ";
    }
    cout << "\n\n";

    // Encabezado
    cout << "     ";
    for (size_t j = 0; j < matAdj.size(); j++) {
        cout << "  N" << j << "  ";
    }
    cout << "\n     ";
    for (size_t j = 0; j < matAdj.size(); j++) {
        cout << "------";
    }
    cout << endl;

    // Filas
    for (size_t i = 0; i < matAdj.size(); i++) {
        cout << "N" << i << " |";
        for (size_t j = 0; j < matAdj[i].size(); j++) {
            if (matAdj[i][j] < 0) {
                cout << "  -   ";
            }
            else if (i == j) {
                cout << "  0   ";
            }
            else {
                cout << fixed << setprecision(1) << setw(5) << matAdj[i][j] << " ";
            }
        }
        cout << "|" << endl;
    }

    cout << "     ";
    for (size_t j = 0; j < matAdj.size(); j++) {
        cout << "------";
    }
    cout << endl;
}

// Función para crear un MapaSolucio de prueba
MapaSolucio crearMapaPrueba() {
    MapaSolucio mapa;

    // Crear algunos caminos de prueba
    vector<Coordinate> camino1 = {
        Coordinate{41.491, 2.142},  // Nodo A
        Coordinate{41.492, 2.143},  // Nodo B
        Coordinate{41.493, 2.144}   // Nodo C
    };

    vector<Coordinate> camino2 = {
        Coordinate{41.493, 2.144},  // Nodo C (mismo que final de camino1)
        Coordinate{41.494, 2.145}   // Nodo D
    };

    vector<Coordinate> camino3 = {
        Coordinate{41.491, 2.142},  // Nodo A
        Coordinate{41.495, 2.146}   // Nodo E
    };

    // Añadir caminos al mapa
    CamiSolucio* cami1 = new CamiSolucio(camino1);
    CamiSolucio* cami2 = new CamiSolucio(camino2);
    CamiSolucio* cami3 = new CamiSolucio(camino3);

    // Necesitamos acceder al vector m_camins (lo haremos de forma diferente)
    // En lugar de eso, vamos a crear un vector de XmlElements simulado

    return mapa;
}

int main() {
    cout << "=== TEST GRAF SOLUCIÓ ===" << endl;
    cout << "=========================" << endl;

    // ------------------------------------------------------------------
    // TEST 1: Constructor por defecto
    // ------------------------------------------------------------------
    cout << "\n1. TEST CONSTRUCTOR POR DEFECTO:" << endl;
    cout << "--------------------------------" << endl;
    GrafSolucio graf1;
    cout << "Nodos: " << graf1.getNumNodes() << endl;
    cout << "Aristas: " << graf1.getNumArestes() << endl;

    // ------------------------------------------------------------------
    // TEST 2: Añadir nodos individualmente
    // ------------------------------------------------------------------
    cout << "\n2. TEST AÑADIR NODOS:" << endl;
    cout << "---------------------" << endl;

    Coordinate nodoA{ 41.491, 2.142 };
    Coordinate nodoB{ 41.492, 2.143 };
    Coordinate nodoC{ 41.493, 2.144 };
    Coordinate nodoD{ 41.494, 2.145 };

    graf1.afegirNode(nodoA);
    cout << "Añadido nodo A - Nodos: " << graf1.getNumNodes() << endl;

    graf1.afegirNode(nodoB);
    cout << "Añadido nodo B - Nodos: " << graf1.getNumNodes() << endl;

    graf1.afegirNode(nodoC);
    cout << "Añadido nodo C - Nodos: " << graf1.getNumNodes() << endl;

    graf1.afegirNode(nodoD);
    cout << "Añadido nodo D - Nodos: " << graf1.getNumNodes() << endl;

    // Intentar añadir nodo duplicado
    graf1.afegirNode(nodoA);
    cout << "Intentar añadir nodo A (duplicado) - Nodos: " << graf1.getNumNodes() << endl;

    // ------------------------------------------------------------------
    // TEST 3: Buscar nodos con inM_Nodes
    // ------------------------------------------------------------------
    cout << "\n3. TEST BUSCAR NODOS:" << endl;
    cout << "---------------------" << endl;

    cout << "Buscar nodo A: posición " << graf1.inM_Nodes(nodoA) << endl;
    cout << "Buscar nodo B: posición " << graf1.inM_Nodes(nodoB) << endl;
    cout << "Buscar nodo C: posición " << graf1.inM_Nodes(nodoC) << endl;
    cout << "Buscar nodo D: posición " << graf1.inM_Nodes(nodoD) << endl;

    Coordinate nodoE{ 41.500, 2.150 };  // Nodo que no existe
    cout << "Buscar nodo E (no existe): posición " << graf1.inM_Nodes(nodoE) << endl;

    // ------------------------------------------------------------------
    // TEST 4: Añadir aristas
    // ------------------------------------------------------------------
    cout << "\n4. TEST AÑADIR ARISTAS:" << endl;
    cout << "------------------------" << endl;

    cout << "Aristas antes: " << graf1.getNumArestes() << endl;

    graf1.afegirAresta(nodoA, nodoB);
    cout << "Añadida arista A-B. Aristas: " << graf1.getNumArestes() << endl;

    graf1.afegirAresta(nodoB, nodoC);
    cout << "Añadida arista B-C. Aristas: " << graf1.getNumArestes() << endl;

    graf1.afegirAresta(nodoC, nodoD);
    cout << "Añadida arista C-D. Aristas: " << graf1.getNumArestes() << endl;

    graf1.afegirAresta(nodoA, nodoD);
    cout << "Añadida arista A-D. Aristas: " << graf1.getNumArestes() << endl;

    // Intentar añadir arista con nodo que no existe
    graf1.afegirAresta(nodoA, nodoE);
    cout << "Intentar añadir arista A-E (E no existe). Aristas: " << graf1.getNumArestes() << endl;

    // Visualizar matriz
    visualizarMatriz(graf1.getMatAdj(), graf1.getNodes());

    // ------------------------------------------------------------------
    // TEST 5: Eliminar aristas
    // ------------------------------------------------------------------
    cout << "\n5. TEST ELIMINAR ARISTAS:" << endl;
    cout << "--------------------------" << endl;

    cout << "Aristas antes de eliminar: " << graf1.getNumArestes() << endl;
    graf1.eliminarAresta(nodoB, nodoC);
    cout << "Eliminada arista B-C. Aristas: " << graf1.getNumArestes() << endl;

    visualizarMatriz(graf1.getMatAdj(), graf1.getNodes());

    // ------------------------------------------------------------------
    // TEST 6: Eliminar nodo
    // ------------------------------------------------------------------
    cout << "\n6. TEST ELIMINAR NODO:" << endl;
    cout << "----------------------" << endl;

    cout << "ANTES de eliminar nodo C:" << endl;
    cout << "Nodos: " << graf1.getNumNodes() << endl;
    cout << "Aristas: " << graf1.getNumArestes() << endl;

    graf1.eliminarNode(nodoC);

    cout << "\nDESPUÉS de eliminar nodo C:" << endl;
    cout << "Nodos: " << graf1.getNumNodes() << endl;
    cout << "Aristas: " << graf1.getNumArestes() << endl;

    visualizarMatriz(graf1.getMatAdj(), graf1.getNodes());

    // Verificar que nodo C ya no existe
    cout << "Buscar nodo C después de eliminarlo: posición " << graf1.inM_Nodes(nodoC) << endl;

    // ------------------------------------------------------------------
    // TEST 7: Constructor con matriz
    // ------------------------------------------------------------------
    cout << "\n7. TEST CONSTRUCTOR CON MATRIZ:" << endl;
    cout << "-------------------------------" << endl;

    vector<Coordinate> nodes2 = { nodoA, nodoB, nodoD };
    vector<vector<double>> matAdj2 = {
        {0, 5.5, 8.2},
        {5.5, 0, -1},
        {8.2, -1, 0}
    };

    GrafSolucio graf2(nodes2, matAdj2);
    cout << "Graf2 creado con matriz 3x3" << endl;
    cout << "Nodos: " << graf2.getNumNodes() << endl;
    cout << "Aristas: " << graf2.getNumArestes() << endl;

    visualizarMatriz(graf2.getMatAdj(), graf2.getNodes());

    // ------------------------------------------------------------------
    // TEST 8: Operador de asignación
    // ------------------------------------------------------------------
    cout << "\n8. TEST OPERADOR DE ASIGNACIÓN:" << endl;
    cout << "-------------------------------" << endl;

    GrafSolucio graf3;
    graf3 = graf2;

    cout << "Graf3 = Graf2" << endl;
    cout << "Graf3 Nodos: " << graf3.getNumNodes() << endl;
    cout << "Graf3 Aristas: " << graf3.getNumArestes() << endl;

    // Modificar graf3 para verificar que son copias independientes
    graf3.afegirNode(nodoC);
    cout << "\nAñadido nodo C a Graf3:" << endl;
    cout << "Graf3 Nodos: " << graf3.getNumNodes() << endl;
    cout << "Graf2 Nodos: " << graf2.getNumNodes() << " (debe seguir siendo 3)" << endl;

    // ------------------------------------------------------------------
    // TEST 9: Constructor de copia
    // ------------------------------------------------------------------
    cout << "\n9. TEST CONSTRUCTOR DE COPIA:" << endl;
    cout << "------------------------------" << endl;

    GrafSolucio graf4(graf2);
    cout << "Graf4 creado como copia de Graf2" << endl;
    cout << "Graf4 Nodos: " << graf4.getNumNodes() << endl;
    cout << "Graf4 Aristas: " << graf4.getNumArestes() << endl;

    visualizarMatriz(graf4.getMatAdj(), graf4.getNodes());

    // ------------------------------------------------------------------
    // TEST 10: Calcular distancias reales
    // ------------------------------------------------------------------
    cout << "\n10. TEST DISTANCIAS REALES:" << endl;
    cout << "---------------------------" << endl;

    GrafSolucio graf5;

    Coordinate punto1{ 41.4914503, 2.1416965 };
    Coordinate punto2{ 41.4914870, 2.1406742 };
    Coordinate punto3{ 41.4905000, 2.1420000 };

    graf5.afegirNode(punto1);
    graf5.afegirNode(punto2);
    graf5.afegirNode(punto3);

    graf5.afegirAresta(punto1, punto2);
    graf5.afegirAresta(punto2, punto3);
    graf5.afegirAresta(punto1, punto3);

    cout << "Grafo con coordenadas reales:" << endl;
    cout << "Nodos: " << graf5.getNumNodes() << endl;
    cout << "Aristas: " << graf5.getNumArestes() << endl;

    visualizarMatriz(graf5.getMatAdj(), graf5.getNodes());

    // Mostrar distancias reales
    vector<Coordinate> nodes = graf5.getNodes();
    vector<vector<double>> mat = graf5.getMatAdj();

    cout << "\nDistancias calculadas con Haversine:" << endl;
    for (size_t i = 0; i < nodes.size(); i++) {
        for (size_t j = i + 1; j < nodes.size(); j++) {
            if (mat[i][j] >= 0) {
                cout << "N" << i << " -> N" << j << ": "
                    << fixed << setprecision(2) << mat[i][j] << " metros" << endl;
            }
        }
    }

    cout << "\n=== TODOS LOS TESTS COMPLETADOS ===" << endl;
    cout << "===================================" << endl;

    return 0;
}