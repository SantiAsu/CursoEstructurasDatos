//Tarea 2: Implementar una cola usando dos pilas

#include <iostream>
#include <stack>
using namespace std;

class queueUsingTwoStacks {
private:
    stack<int> entrada;
    stack<int> salida;

    void transferir() {
        while (!entrada.empty()) {
            salida.push(entrada.top());//agregar el ulltimo elemento de entrada
            entrada.pop();  //elimina
        }
    }
public:
    //agregar
    void enqueue(int valor) {
        entrada.push(valor);
        cout << "Valor insertado: " << valor << endl;
    }

    //eliminar y devolver elemento al frente de la cola
    int dequeue() {
        if (salida.empty()) {
           if (entrada.empty()) {
               cout << "La cola esta vacia" << endl;
               return -1;
           }
            transferir();//transferir elementos de entrada a salida
        }
        int valor = salida.top();
        salida.pop();
        cout << "Valor eliminado: " << valor << endl;
        return valor;
    }

    int front() {
        if (salida.empty()) {
            if (entrada.empty()) {
                cout << "La cola esta vacia" << endl;
                return -1;
            }
            transferir();//transferir elementos de entrada a salida
        }
        return salida.top();
    }

    bool isEmpty() {
        return entrada.empty() && salida.empty();
    }
};

int main() {
    queueUsingTwoStacks cola;
    cola.enqueue(10);
    cola.enqueue(20);
    cola.enqueue(5);
    cola.enqueue(30);


    cout << "Elemento de la cima es: "<<cola.front() << endl;

    cout << "Elemento eliminado: "<< cola.dequeue() << endl;
    cout << "Elemento eliminado: "<< cola.dequeue() << endl;

    //verificar si esta vacia
    if (cola.isEmpty()) {
        cout << "La cola esta vacia" << endl;
    } else {
        cout << "La cola no esta vacia" << endl;
    }

    cout << "Elemento de la cima es: "<<cola.front() << endl;
}