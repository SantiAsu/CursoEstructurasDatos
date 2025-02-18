#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // Incluir esta biblioteca para usar reverse
using namespace std;

class Grafo {
private:
    int numNodos;
    vector<vector<int>> listaAdyacencia;

public:
    Grafo(int n) : numNodos(n), listaAdyacencia(n) {}

    void agregarArista(int u, int v) {
        listaAdyacencia[u].push_back(v);
        listaAdyacencia[v].push_back(u);
    }

    vector<int> caminoMasCorto(int inicio, int fin) {
        vector<bool> visitado(numNodos, false); //todos falsos
        vector<int> padre(numNodos, -1); // Para reconstruir el camino
        queue<int> cola;

        visitado[inicio] = true;
        cola.push(inicio);

        while (!cola.empty()) {
            int nodoActual = cola.front();
            cola.pop(); //eliminamos para procesarlo

            // Si llegamos al nodo final, reconstruimos el camino
            if (nodoActual == fin) {
                return reconstruirCamino(padre, inicio, fin);
            }

            // Recorrer todos los nodos adyacentes
            for (int adyacente : listaAdyacencia[nodoActual]) {
                if (!visitado[adyacente]) {
                    visitado[adyacente] = true;
                    padre[adyacente] = nodoActual; // Guardar el padre
                    cola.push(adyacente);
                }
            }
        }

        return {}; // Si no hay camino
    }

private:
    vector<int> reconstruirCamino(vector<int>& padre, int inicio, int fin) {
        vector<int> camino;
        for (int v = fin; v != -1; v = padre[v]) {
            camino.push_back(v);
        }
        reverse(camino.begin(), camino.end()); // Invertir para obtener el orden correcto
        return camino;
    }
};

int main() {
    // Crear un grafo con 6 nodos
    Grafo grafo(7);

    // Agregar aristas (conexiones entre nodos)
    grafo.agregarArista(0, 1);
    grafo.agregarArista(0, 2);
    grafo.agregarArista(1, 3);
    grafo.agregarArista(2, 4);
    grafo.agregarArista(3, 5);

    grafo.agregarArista(0, 5);

    // Encontrar el camino más corto entre el nodo 0 y el nodo 5
    vector<int> camino = grafo.caminoMasCorto(0, 5);

    // Imprimir el camino
    if (!camino.empty()) {
        cout << "Camino mas corto: ";
        for (int nodo : camino) {
            cout << nodo << " ";
        }
        cout << endl;
    } else {
        cout << "No hay camino entre los nodos." << endl;
    }

    return 0;
}