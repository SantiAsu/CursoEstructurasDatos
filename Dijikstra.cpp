//camino mas corto con grafos con peso
//Usa una cola de prioridad (min-heap) para seleccionar siempre el nodo con la distancia acumulada más corta.
#include <iostream>
#include <vector>
#include <queue> // Para priority_queue
#include <climits> // Para INT_MAX
using namespace std;

typedef pair<int,int> pii; //distancia, nodo

class Grafo {
private:
    int numNodos;
    vector<vector<pii>> listaAdyacencia;

public:
    Grafo(int n): numNodos(n), listaAdyacencia(n) {}

    void agregarArista(int u, int v, int peso) {
        listaAdyacencia[u].push_back({v, peso});
        listaAdyacencia[v].push_back({u, peso});
    }

    vector<int> dijkstra(int inicio) {
        vector<int> distancia(numNodos, INT_MAX); //vector q guardara distancias
        distancia[inicio] = 0;

        //creacion min heap, ordenamiento para el mas corto
        priority_queue<pii, vector<pii>, greater<pii>> cola; //conjunto en el que siempre escojeremos el menor

        cola.push({0, inicio});//agregamos que el nodo 0 con distancia de inicio 0

        //procesamos todo los posibles resultados
        while(!cola.empty()) {

            //aqui extraemos el de menor distancia siempre
            int distActual = cola.top().first;//dit acumulada
            int nodoActual = cola.top().second; //nodo actual

            cola.pop(); // lo eliminamos para poder procesarlo y no sea doble

            if(distActual < distancia[nodoActual]) continue;

            for (auto& vecino : listaAdyacencia[nodoActual]) {
                int nodoVecino = vecino.first;
                int peso   = vecino.second;
                int nuevadist = distActual + peso; //distancia acumulada en total de la anetior + vecinos

                //actualizamos
                if(nuevadist < distancia[nodoVecino]) {
                    distancia[nodoVecino] = nuevadist;
                    cola.push({nuevadist, nodoVecino});
                }
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

    vector<int> distancias = grafo.dijkstra(0);
    cout << "Distancias minimas desde el nodo 0:\n";
    for (int i = 0; i < distancias.size(); i++) {
        cout << "Nodo " << i << ": " << distancias[i] << endl;
    }
    return 0;
}