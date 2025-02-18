
#include <iostream>
using namespace std;
//lifa last in, first out,, último en entrar, primero en salir
struct Nodo {
    int dato;
    Nodo* siguiente;
};

//agregar al final
void push(Nodo*& cima, int valor) {
    Nodo* nuevoNodo = new Nodo{valor, cima};
    cima = nuevoNodo;
    cout << "Nodo con valor " << valor << " insertado." << endl;
}

//mostrar
int peek(Nodo* cima) {

    if (cima == nullptr) {
        cout << "La pila esta vacia" << endl;
        return -1;
    }
    return cima->dato;
}

//eliminar el ultimo
int pop(Nodo*& cima) {
    if (cima == nullptr) {
        cout << "La pila esta vacia" << endl;
        return -1;
    }

    int valor = cima->dato;
    Nodo* temp = cima;
    cima = cima->siguiente;
    delete temp;
    cout << "Elemento eliminado: " << valor << endl;
    return valor;
}

bool isEmpty(Nodo* cima) {
    return cima == nullptr;
}

int main() {
    Nodo* cima = nullptr;

    push(cima,10);
    push(cima,20);
    push(cima,30);

    cout << "Elemento de la cima es: "<<peek(cima) << endl;

    //Eliminar elementos de la pila
    cout << "Elemento eliminado: "<< pop(cima) << endl;
    cout << "Elemento eliminado: "<< pop(cima) << endl;

    //verificamoa si esta vacia
    if (isEmpty(cima)) {
        cout << "La pila esta vacia" << endl;
    }else{ cout << "La pila no esta vacia" << endl;}


    //liberamos memoria
    while (!isEmpty(cima)) {
        pop(cima);
    }

}