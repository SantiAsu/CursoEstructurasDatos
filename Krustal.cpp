//Usaremos en este algoritmo algo llamado union-find
//Union-Find es una estructura de datos que nos ayuda a agrupar
//elementos y verificar si están en el mismo grupo, lo que lo
//hace perfecto para evitar ciclos en Kruskal al construir el MST.
//es un algoritmo de optimizacion, minimizando gefos al minimo peso posible pasando por todos los nodos
#include <iostream>
#include <vector>
#include <algorithm> // Para sort
using namespace std;

struct Arista {
    int u,v, peso;
    bool operator<(const Arista& otra) const {
        return peso < otra.peso; //sobre carga del operador <. nosotros establecemos como debe de funcionar
    }
};

class Unionfind {
private:
    vector<int> padre, rango;
public:

    Unionfind(int n):   padre(n), rango(n,1) {
        for(int i=0;i<n;i++) {
            padre[i] = i; //esto significa que cada noso es su propio padre
        }
    }
    int encontrar(int u) {
        if(padre[u]!=u) {
            padre[u] = padre[padre[u]]; //compresion de camino
        }
        return padre[u];
    }

    void unir(int u, int v) {
        int raizU = encontrar(u);
        int raizV = encontrar(v);

        if (raizU != raizV) {
            if (rango[raizU] > rango[raizV]) {
                padre[raizV] = raizU;
            } else if (rango[raizU] < rango[raizV]) {
                padre[raizU] = raizV;
            } else {
                padre[raizV] = raizU;
                rango[raizU]++;
            }
        }
    }
};

class Grafo {
private:
    int numNodos;
    vector<Arista> aristas;
public:

    Grafo(int n) : numNodos(n) {}

    void agregarArista(int u, int v, int peso) {
        aristas.push_back(Arista{u,v,peso});

    }

    vector<Arista > Krustal() {
        vector<Arista> mst; //almacena aristas
        Unionfind uf(numNodos); //estructura union find

        //ordenacion por peso
        sort(aristas.begin(), aristas.end());

        for (Arista& arista : aristas) {
            int u = arista.u, v = arista.v;

            if (uf.encontrar(u) != uf.encontrar(v)) { //si no forman un ciclo...
                mst.push_back(arista); // lo metemos a la lista
                uf.unir(u,v); //unimos conjuntos
            }
        }
        return mst;
    }
};


int main() {
    Grafo grafo(4);
    grafo.agregarArista(0, 1, 10);
    grafo.agregarArista(0, 2, 6);
    grafo.agregarArista(0, 3, 5);
    grafo.agregarArista(1, 3, 15);
    grafo.agregarArista(2, 3, 4);

    vector<Arista> mst = grafo.Krustal();
    cout << "Aristas del MST:\n";
    for (Arista& arista : mst) {
        cout << arista.u << " - " << arista.v << " : " << arista.peso << endl;
    }

    return 0;
}
