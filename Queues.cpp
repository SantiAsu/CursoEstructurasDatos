
#include <iostream>
using namespace std;
//las colas son FIFO (First In, First Out), es decir, el primer elemento en entrar es el primero en salir.
struct Nodo {
    int dato;
    Nodo* siguiente;
};
void enqueue(Nodo*& frente, Nodo*& final, int valor) {
    Nodo* nuevoNodo = new Nodo{valor, nullptr};
    if (final == nullptr) {
        frente = nuevoNodo;
    } else {
        final->siguiente= nuevoNodo;//el ultimo apunta al nuevo
    }
    final = nuevoNodo;//el nuevo es el ultimo
    cout << "Nodo con valor " << valor << " insertado." << endl;
}

int dequeue (Nodo*& frente, Nodo*& final) {
    if (frente == nullptr) {
        cout << "La cola esta vacia" << endl;
        return -1;
    }
    int valor = frente->dato;
    Nodo* temp = frente;
    frente = frente->siguiente;
    if (frente == nullptr) { //si la cola esta vacia el final tambien
        final = nullptr;
    }
    delete temp;
    cout << "Elemento eliminado: " << valor << endl;
    return valor;
}

int front(Nodo* frente) {
    if (frente == nullptr) {
        cout << "La cola esta vacia" << endl;
        return -1;
    }
    return frente->dato;
}
bool isEmpty(Nodo* frente) {
    return frente == nullptr; //devuelvue true su es nulo el frente
}

int main() {

    Nodo* frente = nullptr;
    Nodo* final = nullptr;

    enqueue(frente, final, 10);
    enqueue(frente, final, 20);
    enqueue(frente, final, 30);

    cout << "Elemento de la cima es: "<<front(frente) << endl;

    //eliminamos
    cout << "Elemento eliminado: "<< dequeue(frente,final) << endl;
    cout << "Elemento eliminado: "<< dequeue(frente,final) << endl;


    cout << "Elemento de la cima es: "<<front(frente) << endl;

    //verificamos si esta vacia
    if (isEmpty(frente)) {
        cout << "La cola esta vacia" << endl;
    } else {
        cout << "La cola no esta vacia" << endl;
    }

    //liberamos memoria
    while (!isEmpty(frente)) {
        dequeue(frente,final);
    }

    return 0;
}


