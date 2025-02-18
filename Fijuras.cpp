#include <iostream>
#include <conio.h>

using namespace std;

int triangulo() {
    cout<<"Dijite el numero de filas que querra: "<<endl;
    int filas;
    cin>>filas;

    for(int i=0;i<filas;i++) {
        for (int j=0; j<filas-i;j++) {
            cout<<" ";
        }
        for (int k=0; k<i*2+1;k++) {
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}

int cuadroConRelleno() {
    cout<<"Dijite el numero de filas que querra: "<<endl;
    int filas;
    cin>>filas;

    for(int i=0;i<=filas;i++) {
        for (int j=0; j<=filas;j++) {
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}

int main() {
    cout<<"Dijite el numero de filas que querra: "<<endl;
    int filas;
    cin>>filas;
    for(int i=0;i<=filas;i++) {
        for (int j=0; j<=filas;j++) {
            if(i==0 || i==filas-1 || j==0 || j==filas-1) {
                cout<<"* ";
            }
            else {
                cout<<" ";
            }
        }
        cout<<endl;
    }
}