//algoritmo dijikstra pero con pesos negativos
#include <iostream>
#include <vector>

#include <climits> // Para INT_MAX
using namespace std;

struct Arista {
    int origen, destino, peso;
};

class Grafo {
private:
    int numNodos;
    vector<Arista> aristas;
public:
    Grafo(int n) : numNodos(n) {}

    void agregarArista(int u, int v, int peso) {
        aristas.push_back({u,v,peso});
    }

    vector<int> bellmanFord(int inicio) {
        vector<int> distancia(numNodos, INT_MAX);
        distancia[inicio] = 0;

        //relajamos las aristas V-1 veces
        for (int i = 0; i < numNodos-1; i++) {
            for (Arista& arista : aristas) {
                if (distancia[arista.origen] != INT_MAX &&
                    distancia[arista.origen] + arista.peso < distancia[arista.destino]) {
                    distancia[arista.destino] = distancia[arista.origen] + arista.peso;
                }
            }
        }


        // Detectar ciclos negativos (V-ésima iteración)
        for (Arista& arista : aristas) {
            if (distancia[arista.origen] != INT_MAX &&
                distancia[arista.origen] + arista.peso < distancia[arista.destino]) {
                cout << "¡El grafo contiene un ciclo negativo!" << endl;
                return {}; // Retorna un vector vacío
                }
        }
        return distancia;
    }
};


int main() {
    Grafo grafo(5);
    grafo.agregarArista(0, 1, 4);
    grafo.agregarArista(0, 2, 1);
    grafo.agregarArista(2, 1, 2);
    grafo.agregarArista(2, 3, 5);
    grafo.agregarArista(1, 3, 1);
    grafo.agregarArista(3, 4, 3);

    vector<int> distancias = grafo.bellmanFord(0);
    if (!distancias.empty()) {
        cout << "Distancias minimas desde el nodo 0:\n";
        for (int i = 0; i < distancias.size(); i++) {
            cout << "Nodo " << i << ": " << distancias[i] << endl;
        }
    }

    return 0;
}