#include <iostream>
#include <vector>
#include <queue> // Para BFS
using namespace std;

class Grafo {
private:
    int numNodos;
    vector<vector<int>> listaAdyacencia;
    public:
    Grafo(int n): numNodos(n), listaAdyacencia(n) {}

    void agregarArista(int u, int v) {
        listaAdyacencia[u].push_back(v);
        listaAdyacencia[v].push_back(u);
    }

    bool tieneCiclo() {
        vector<bool> visitado(numNodos, false); //esto inicializa todos los valores en false
        for (int i = 0; i < numNodos; i++) {
            if (!visitado[i]) {
                if (DFS(i,-1,visitado)) {
                    return true;//hay ciclo
                }

            }
        }
        return false;//no hay sahdahfah
    }

private:
    bool DFS(int nodo, int padre, vector<bool>& visitado) {
        visitado[nodo] = true;//lo agregamos como visitado

        for (int adyacente : listaAdyacencia[nodo]) {
            if (!visitado[adyacente]) {
                //forma simplificada de recorrer todos los elementos de un contenedor
                if (DFS(adyacente,nodo,visitado)) {
                    return true;
                }
                else if (adyacente != padre) {
                    return true; //hay ciclo
                }
            }
        }
        return false;
    }

};


int main() {

    Grafo grafo(5);


    grafo.agregarArista(0, 1);
    grafo.agregarArista(1, 2);
    grafo.agregarArista(2, 3);
    grafo.agregarArista(3, 4);
    grafo.agregarArista(4, 5); // Esta arista crea un ciclo

    // Verificar si el grafo tiene ciclos
    if (grafo.tieneCiclo()) {
        cout << "El grafo tiene ciclos." << endl;
    } else {
        cout << "El grafo no tiene ciclos." << endl;
    }

    return 0;
}