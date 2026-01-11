#include "Graf.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    try {
        cout << "=== PRUEBA DE GRAFO NO DIRIGIDO SIN PESOS ===\n";
        
        // Crear grafo no dirigido sin pesos
        vector<string> nodes = {"A", "B", "C", "D"};
        vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
        
        Graf g1(nodes, edges, false);
        cout << "Matriz de adyacencia:\n";
        g1.mostra();
        
        cout << "\nGrado de salida de A: " << g1.grauOutNode("A") << endl;
        cout << "Grado de entrada de C: " << g1.grauInNode("C") << endl;
        
        // BFS
        cout << "\nBFS desde A: ";
        queue<string> bfsResult;
        g1.BFS("A", bfsResult);
        while (!bfsResult.empty()) {
            cout << bfsResult.front() << " ";
            bfsResult.pop();
        }
        cout << endl;
        
        // DFS
        cout << "\nDFS (recursivo) desde A: ";
        vector<string> dfsResult;
        g1.DFS("A", dfsResult, true);
        for (const auto& node : dfsResult) {
            cout << node << " ";
        }
        cout << endl;
        
        // Ciclos
        auto ciclos = g1.cicles();
        cout << "\nCiclos encontrados: " << ciclos.size() << endl;
        
        cout << "\n=== PRUEBA DE GRAFO DIRIGIDO CON PESOS ===\n";
        
        // Grafo dirigido con pesos
        vector<string> nodes2 = {"X", "Y", "Z", "W"};
        vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
        vector<int> pesos = {5, 3, 1, 4};
        
        Graf g2(nodes2, edges2, pesos, true);
        cout << "Matriz de adyacencia (dirigido con pesos):\n";
        g2.mostra();
        
        // Dijkstra
        cout << "\nDijkstra desde X:\n";
        vector<int> distancias;
        g2.dijkstra(0, distancias);
        for (size_t i = 0; i < distancias.size(); i++) {
            cout << "Distancia a " << nodes2[i] << ": ";
            if (distancias[i] == Graf::DISTMAX)
                cout << "INF";
            else
                cout << distancias[i];
            cout << endl;
        }
        
        // Camino más corto
        cout << "\nCamino más corto de X a W:\n";
        stack<string> camino;
        g2.camiMesCurt("X", "W", camino);
        if (!camino.empty()) {
            while (!camino.empty()) {
                cout << camino.top();
                camino.pop();
                if (!camino.empty()) cout << " -> ";
            }
            cout << endl;
        } else {
            cout << "No hay camino\n";
        }
        
        // Añadir nodo
        cout << "\nAñadiendo nodo 'V':\n";
        g2.afegirNode("V");
        g2.inserirAresta(3, 4, 2);  // W -> V con peso 2
        g2.mostra();
        
        // Todos los caminos
        cout << "\nTodos los caminos de X a W:\n";
        vector<list<string>> todosCaminos;
        g2.camins("X", "W", todosCaminos);
        cout << "Total caminos encontrados: " << todosCaminos.size() << endl;
        
        // Eliminar nodo
        cout << "\nEliminando nodo 'Z':\n";
        g2.eliminarNode("Z");
        g2.mostra();
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    
    return 0;
}