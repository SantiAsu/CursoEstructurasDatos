#include <iostream>
using namespace std;

//Bases
int BasesPunteros () {
    //Ejemplo de arreglos con punteros
    int arr[3] = {1,2,3};
    int* ptr = arr; //va a la direccion de memoria

    //va hacia los valores gracias a *
    std::cout << (*ptr)<<std::endl;
    std::cout << (*ptr+1)<<std::endl;
    std::cout << (*ptr+2)<<std::endl;
    //va a la direccion de memoria
    std::cout << (ptr)<<std::endl;
    std::cout << (ptr+1)<<std::endl;
    std::cout << (ptr+2)<<std::endl;

    //Punteros y su direccion de Memoria

    int* ptr2 = new int; // Asigna memoria para un entero, sin esta parte sale error
    *ptr2 = 42;
    std::cout << *ptr2 << std::endl;
    delete ptr2; // Libera la memoria


    //Punteros y arregos Dinamicos
    int* arr2 = new int[5]; // Arreglo dinámico de 5 enteros
    arr2[0] = 10; // Acceso al primer elemento
    delete[] arr2; // Liberar memoria del arreglo

    return 0;
}

//Ejercicio 01. Creacion arreglo dinamico,
int ArregloDinamico() {
    int n;
    cout << "Ingrese el numero de elementos del arreglo"<<endl;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Ingrese el elemento "<<i<<endl;
        cin >> arr[i];
    }

    cout << "El arreglo inverso es: \n";
    for (int i = n-1; i >= 0; i--) {
        cout << *(arr+i)<<endl;
    }

    cout << "El arreglo normal con punteros es: \n";
    for (int i = 0; i < n; i++) {
        cout << *(arr+i)<<endl;
    }

    cout << endl;
    delete[] arr;
    return 0;

}

//Ejercicio cambio de variables con punteros
void intercambiar(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int intercambiarmain() {
    int a = 9, b = 7;

    cout << "Antes de intercambiar: x: "<<a<<" y y: "<< b<<endl;
    intercambiar(&a,&b);
    cout << "Despues de intercambiar: x: "<<a<<" y y: "<< b<<endl;



    return 0;
}

//Prolema usando operadores *, &, ->
class estudiantes {
public:
    int edad;
    string nombre;
    void presentarse() {
        cout<<"Hola soy "<< nombre << " y tengo " << edad<<endl;
    }
};
int Operadores() {
    estudiantes e;
    estudiantes* ptr = &e;
    ptr->nombre = "Juan";
    ptr->edad = 20;
    ptr->presentarse();

   // delete ptr; Esto solo se usa cuando creamos un puntero, como es el caso de new
    return 0;
}