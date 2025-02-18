#include <iostream>
#include <vector>
#include <queue> // Para BFS
using namespace std;

class Grafo {
private:
    int numNodos; // Número de nodos
    vector<vector<int>> listaAdyacencia; // Lista de adyacencia

public:
    // Constructor
    Grafo(int n) : numNodos(n), listaAdyacencia(n) {}

    // Agregar una arista (no dirigida)
    void agregarArista(int u, int v) {
        listaAdyacencia[u].push_back(v); // Agregar v a la lista de u
        listaAdyacencia[v].push_back(u); // Agregar u a la lista de v (grafo no dirigido)
    }

    // Imprimir el grafo
    void imprimir() {
        for (int i = 0; i < numNodos; i++) {
            cout << "Nodo " << i << ": ";
            for (int j : listaAdyacencia[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    // Obtener el número de nodos
    int getNumNodos() {
        return numNodos;
    }

    // Obtener la lista de adyacencia de un nodo
    vector<int> getListaAdyacencia(int nodo) {
        return listaAdyacencia[nodo];
    }
};

// Función para recorrido BFS (Búsqueda en Anchura)
void BFS(Grafo& grafo, int inicio) {
    int numNodos = grafo.getNumNodos();
    vector<bool> visitado(numNodos, false); // Vector para marcar nodos visitados
    queue<int> cola; // Cola para BFS

    visitado[inicio] = true; // Marcar el nodo inicial como visitado
    cola.push(inicio); // Agregar el nodo inicial a la cola

    while (!cola.empty()) {
        int nodoActual = cola.front(); // Obtener el nodo actual
        cola.pop(); // Eliminar el nodo de la cola
        cout << nodoActual << " "; // Imprimir el nodo

        // Recorrer todos los nodos adyacentes
        for (int adyacente : grafo.getListaAdyacencia(nodoActual)) {
            if (!visitado[adyacente]) { // Si no ha sido visitado
                visitado[adyacente] = true; // Marcarlo como visitado
                cola.push(adyacente); // Agregarlo a la cola
            }
        }
    }
}

// Función para recorrido DFS (Búsqueda en Profundidad)
void DFS(Grafo& grafo, int inicio, vector<bool>& visitado) {
    visitado[inicio] = true; // Marcar el nodo actual como visitado
    cout << inicio << " "; // Imprimir el nodo

    // Recorrer todos los nodos adyacentes
    for (int adyacente : grafo.getListaAdyacencia(inicio)) {
        if (!visitado[adyacente]) { // Si no ha sido visitado
            DFS(grafo, adyacente, visitado); // Llamar a DFS recursivamente
        }
    }
}

int main() {

    Grafo grafo(6);


    grafo.agregarArista(0, 1);
    grafo.agregarArista(0, 2);
    grafo.agregarArista(1, 3);
    grafo.agregarArista(1, 4);
    grafo.agregarArista(2, 5);


    cout << "Lista de adyacencia:" << endl;
    grafo.imprimir();


    cout << "Recorrido BFS (empezando desde el nodo 0): ";
    BFS(grafo, 0);
    cout << endl;


    cout << "Recorrido DFS (empezando desde el nodo 0): ";
    vector<bool> visitado(grafo.getNumNodos(), false); // Vector para marcar nodos visitados
    DFS(grafo, 0, visitado);
    cout << endl;

    return 0;
}