//Estructura de dato de un arbol binario

#include <iostream>
using namespace std;

    struct Nodo {
        int dato;
        Nodo* izquierdo;
        Nodo* derecho;

        //constructor
        Nodo(int valor) : dato(valor), izquierdo(nullptr), derecho(nullptr) {}
    };

//Funcion para insertar
Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == nullptr) {
        return new Nodo(valor);
    }
    if (valor < raiz->dato) { //si es menor se insertara a la izquierda
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    } else if (valor > raiz->dato) {
        raiz->derecho = insertar(raiz->derecho, valor);
    }
    return raiz;
}

//recorrido en inorden
//Inorden: Izquierda -> Raíz -> Derecha.
void inorden(Nodo* raiz) {
    if (raiz != nullptr) {
        inorden(raiz->izquierdo); // Recorrer subárbol izquierdo
        cout << raiz->dato << " "; // Visitar raíz
        inorden(raiz->derecho); // Recorrer subárbol derecho
    }
}

//recorrido en preorden
//Preorden: Raíz -> Izquierda -> Derecha.
void preorden(Nodo* raiz) {
    if (raiz != nullptr) {
        cout<<raiz->dato<<" ";
        preorden(raiz->izquierdo);
        preorden(raiz->derecho);
    }
}

//recorrido en postorden
//Postorden: Izquierda -> Derecha -> Raíz.
void postorden(Nodo* raiz) {
    if (raiz != nullptr) {
        postorden(raiz->izquierdo);
        postorden(raiz->derecho);
        cout<<raiz->dato<<" ";
    }
}

//se usa bool para mas practicidad
bool buscar(Nodo* raiz, int valor) {
    if (raiz == nullptr) {
        return false;
    }
    if (valor == raiz->dato) {
        return true;
    }
    if (valor < raiz->dato) {
        return buscar(raiz->izquierdo, valor);
    } else {
        return buscar(raiz->derecho, valor);
    }
}

// Función para calcular la altura del árbol
int altura(Nodo* raiz) {
    if (raiz == nullptr) {
        return 0;
    }
    int alturaIzquierda = altura(raiz->izquierdo);
    int alturaDerecha = altura(raiz->derecho);
    return 1 + max(alturaIzquierda, alturaDerecha);
}

// Función para contar el número de nodos
int contarNodos(Nodo* raiz) {
    if (raiz == nullptr) {
        return 0;
    }
    return 1 + contarNodos(raiz->izquierdo) + contarNodos(raiz->derecho);
}

int main() {
    Nodo* raiz = nullptr;//arbol vacio

    raiz = insertar(raiz, 50);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 70);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 60);
    raiz = insertar(raiz, 80);

    //recorridos
    cout << "Recorrido en inorden: "<<endl;
    inorden(raiz);
    cout << endl;

    cout<<"Recorrido en preorden: "<<endl;
    preorden(raiz);
    cout << endl;

    cout<<"Recorrido en postorden: "<<endl;
    postorden(raiz);
    cout << endl;

    int valor = 40;
    if (buscar(raiz, valor)) {
        cout << "El valor " << valor << " esta en el arbol." << endl;
    } else {
        cout << "El valor " << valor << " no esta en el árbol." << endl;
    }


    // Calcular altura del árbol
    cout << "Altura del arbol: " << altura(raiz) << endl;

    // Contar número de nodos
    cout << "Numero de nodos: " << contarNodos(raiz) << endl;

    return 0;
}