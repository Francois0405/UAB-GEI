#include "Graf.h"
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

int main() {
    try {
        cout << "=== PRUEBA COMPLETA DE GRAF ===\n";
        
        // 1. Grafo no dirigido sin pesos
        cout << "\n1. GRAFO NO DIRIGIDO SIN PESOS:\n";
        vector<string> nodes = {"A", "B", "C", "D"};
        vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
        
        Graf g1(nodes, edges, false);
        g1.mostra();
        
        cout << "\nGrado salida A: " << g1.grauOutNode("A");
        cout << "\nGrado entrada C: " << g1.grauInNode("C");
        
        // BFS
        cout << "\n\nBFS desde A: ";
        queue<string> bfs;
        g1.BFS("A", bfs);
        while (!bfs.empty()) {
            cout << bfs.front() << " ";
            bfs.pop();
        }
        
        // DFS recursivo
        cout << "\nDFS (recursivo) desde A: ";
        vector<string> dfs;
        g1.DFS("A", dfs, true);
        for (auto& n : dfs) cout << n << " ";
        
        // DFS con pila
        cout << "\nDFS (pila) desde A: ";
        dfs.clear();
        g1.DFS("A", dfs, false);
        for (auto& n : dfs) cout << n << " ";
        
        // Ciclos
        auto ciclos = g1.cicles();
        cout << "\n\nCiclos de 3 nodos: " << ciclos.size();
        for (auto& c : ciclos) {
            cout << "\nCiclo: ";
            for (auto& n : c) cout << g1.getNodes()[n] << " ";
        }
        
        // 2. Grafo dirigido con pesos
        cout << "\n\n2. GRAFO DIRIGIDO CON PESOS:\n";
        vector<string> nodes2 = {"X", "Y", "Z", "W"};
        vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
        vector<int> pesos = {5, 3, 1, 4};
        
        Graf g2(nodes2, edges2, pesos, true);
        g2.mostra();
        
        // Dijkstra
        cout << "\nDijkstra desde X (índice 0):\n";
        vector<int> dist;
        g2.dijkstra(0, dist);
        for (size_t i = 0; i < dist.size(); i++) {
            cout << "Distancia a " << nodes2[i] << ": ";
            if (dist[i] == Graf::DISTMAX) cout << "INF";
            else cout << dist[i];
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
                if (!camino.empty()) cout << " <- ";
            }
        } else {
            cout << "No hay camino";
        }
        
        // 3. Modificar grafo
        cout << "\n\n3. MODIFICACIONES DE GRAFO:\n";
        
        // Añadir nodo
        cout << "\nAñadiendo nodo 'V':\n";
        g2.afegirNode("V");
        g2.inserirAresta(3, 4, 2);  // W -> V con peso 2
        g2.mostra();
        
        // Añadir arista
        cout << "\nAñadiendo arista Y->W con peso 3:\n";
        g2.inserirAresta(1, 3, 3);
        g2.mostra();
        
        // Todos los caminos
        cout << "\nTodos los caminos de X a W:\n";
        vector<list<string>> todosCaminos;
        g2.camins("X", "W", todosCaminos);
        cout << "Encontrados: " << todosCaminos.size() << " caminos\n";
        
        // Eliminar nodo
        cout << "\nEliminando nodo 'Z':\n";
        g2.eliminarNode("Z");
        g2.mostra();
        
        // 4. Prueba de error
        cout << "\n\n4. PRUEBA DE ERRORES:\n";
        try {
            vector<string> dfsErr;
            g2.DFS("NODO_INEXISTENTE", dfsErr, true);
        } catch (const exception& e) {
            cout << "Error capturado: " << e.what() << endl;
        }
        
        cout << "\n=== FIN DE PRUEBAS ===\n";
        system("pause");
    } catch (const exception& e) {
        cerr << "\nERROR GLOBAL: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}