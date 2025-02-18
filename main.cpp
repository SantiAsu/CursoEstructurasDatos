#include <iostream>

class Persona {
public://Esto es para acceder a los datos
    int edad;
    std::string nombre;

    void Saludar() {
        std::cout << "Hola soy "<<nombre<<" y tengo "<<edad<<" años";
    }
};

int P1() {

    Persona p;
    std::cout << "Ingrese su nombre\n";
    std::cin >> p.nombre;
    std::cout << "Ingrese su edad\n";
    std::cin >> p.edad;

    Persona* ptr = &p;
    ptr->Saludar();
    return 0;
}

int suma (int a, int b) {
    return a + b;
}

int main() {
    int x = 5, y = 10;
    int* resultado = new int(suma(x,y));

    std::cout <<"El resultado de la suma 5 y 10 es: "<< *resultado;
    delete resultado; //libera memoria
    return 0;;
}
