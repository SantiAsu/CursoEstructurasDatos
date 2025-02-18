//Tarea 1: Implementar una pila que permita obtener el mínimo elemento en tiempo constante

#include <iostream>
#include <stack>
using namespace std;

class miniStack {
private:
    stack<int> pila;
    stack<int> pilaMinimos;

public:
    void push(int valor) {
        pila.push(valor);
        if (pilaMinimos.empty() || valor <=pilaMinimos.top()) {
            pilaMinimos.push(valor);
        }
        cout << "Valor insertado: " << valor << endl;
    }
    void pop() {
        if (pila.empty()) {
            cout << "La pila esta vacia" << endl;
            return;
        }
        int valor = pila.top();
        pila.pop();
        if (valor == pilaMinimos.top()) {
            pilaMinimos.pop();
        }
        cout << "Valor eliminado: " << valor << endl;
    }
    int top() {
        if (pila.empty()) {
            cout << "La pila esta vacia" << endl;
            return -1;
        }
        return pila.top();
    }

    int getMin() {
        if (pilaMinimos.empty()) {
            cout << "La pila esta vacia" << endl;
            return -1;
        }
        return pilaMinimos.top();
    }
};

int main() {
    miniStack pila;

    pila.push(10);
    pila.push(20);
    pila.push(5);
    pila.push(15);

    cout << "Minimo elemento: " << pila.getMin() << endl;

    pila.pop();
    pila.pop();

    cout << "Minimo elemento: " << pila.getMin() << endl;

    return 0;
}