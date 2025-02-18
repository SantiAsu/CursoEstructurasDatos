#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

void eliminarNodo(Nodo*& cabeza, int valor) {

    // Caso base
    if (cabeza == nullptr) {
        cout << "No hay elementos en la lista" << endl;
        return;
    }

    // Caso 2: El nodo a eliminar es la cabeza
    if (cabeza->dato == valor) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        cout << "Se elimino el nodo con valor " << valor << endl;
        return;
    }

    // Caso 3: El nodo a eliminar esta en medio o al final
    Nodo* actual = cabeza;
    while (actual->siguiente != nullptr && actual->siguiente->dato != valor) {
        actual = actual->siguiente; //avanzaremos al siguiente nodo
    }

    //Si no esta
    if (actual->siguiente == nullptr) {
        cout << "Nodo con valor " << valor << " no encontrado." << endl;
        return;
    }
    //Si esta
    Nodo* temp = actual->siguiente; // Guardar el nodo a eliminar
    actual->siguiente = temp->siguiente; // Saltar el nodo a eliminar
    delete temp; // Eliminar
    cout << "Nodo con valor " << valor << " eliminado." << endl;
}

void insertarNodo(Nodo*& cabeza, int valor, int posicion) {
    Nodo* nuevoNodo = new Nodo{valor, nullptr};

    //caso 1. Insertar al inicio
    if (posicion == 0) {
        nuevoNodo->siguiente = cabeza;//el nuevo nodo apunta a la cabeza actual
        cabeza = nuevoNodo;//el nuevo nodo es la cabeza
        cout << "Nodo con valor " << valor << " insertado en la posicion " << posicion << "." << endl;
        return;
    }

    //caso 2. insertar en una posicion especifica
    Nodo* actual = cabeza;
    for (int i = 0; i < posicion - 1; i++) {
        if (actual == nullptr) {
            cout << "Esta fuera de rango" << endl;
            return;
        }
        actual = actual->siguiente; // Avanzar al nodo anterior a la posición deseada
    }

    nuevoNodo->siguiente = actual->siguiente; // El nuevo nodo apunta al siguiente nodo
    actual->siguiente = nuevoNodo; // El nodo anterior apunta al nuevo nodo
    cout << "Nodo con valor " << valor << " insertado en la posicion " << posicion << "." << endl;
}

int creacion_nodo() {
    Nodo* cabeza = nullptr;
    Nodo* cola = nullptr;

    int n;
    cout << "Ingresa el numero de elementos: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int valor;
        cout << "Ingresa el valor " << i + 1 << ": ";
        cin >> valor;

        //declaracion del nuevo nodo y  su asignacion
        Nodo* nuevoNodo = new Nodo{valor, nullptr};

        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
            cola = nuevoNodo;
        } else {
            cola->siguiente = nuevoNodo;
            cola = nuevoNodo;
        }
    }

    cout << "Lista enlazada: ";
    imprimirLista(cabeza);

    // Liberar memoria
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }

    return 0;
}


void insertarEnPosicion(Nodo*& cabeza, int valor, int posicion) {
    Nodo* nuevoNodo = new Nodo{valor, nullptr};

    if (posicion == 0) {
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
        cout << "Nodo con valor " << valor << " insertado en la posicion " << posicion << "." << endl;
        return;
    }

    Nodo* actual = cabeza;
    for (int i = 0; i < posicion - 1; i++) {
        if (actual == nullptr) {
            cout << "Posición fuera de rango." << endl;
            return;
        }
        actual = actual->siguiente;
    }

    nuevoNodo->siguiente = actual->siguiente;
    actual->siguiente = nuevoNodo;
    cout << "Nodo con valor " << valor << " insertado en la posicion " << posicion << "." << endl;
}


int main() {
    Nodo* cabeza = nullptr;
    Nodo* cola = nullptr;


    insertarEnPosicion(cabeza, 10, 0);
    insertarEnPosicion(cabeza, 20, 1);
    insertarEnPosicion(cabeza, 30, 2);


    cout << "Lista inicial: ";
    imprimirLista(cabeza);

    // Eliminar
    eliminarNodo(cabeza, 20);
    cout << "Lista despues de eliminar: ";
    imprimirLista(cabeza);


    insertarEnPosicion(cabeza, 15, 1);
    cout << "Lista despues de insertar: ";
    imprimirLista(cabeza);


    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }

    return 0;
}