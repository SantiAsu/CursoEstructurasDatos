#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}

// Busca la primera posición donde el valor en el arreglo es mayor o igual al valor objetivo
int lower_bound(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1, result = arr.size();
    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] >= target) {
            result = mid;
            right = mid - 1;  // Seguir buscando a la izquierda
        } else {
            left = mid + 1;
        }
    }
    return result;
}

// Busca la primera posición donde el valor en el arreglo es estrictamente mayor al valor objetivo
int upper_bound(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1, result = arr.size();
    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] > target) {
            result = mid;
            right = mid - 1;  // Seguir buscando a la izquierda
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    vector<int> arr = {1, 3, 5, 5, 5, 5, 7, 9, 11, 13, 15};
    int target = 5;

    if (binarySearch(arr, target)) {
        cout << "Elemento encontrado" << endl;
    } else {
        cout << "Elemento no encontrado" << endl;
    }

    cout << "Elemento primera aparicion cuando el valor es mayor o igual al objetivo: " << arr[lower_bound(arr, target)] << endl;
    cout << "Elemento primer elemento mayor que el buscado: " << arr[upper_bound(arr, target)] << endl;

    cout<<"Ahora lo haremos con libreria algorithm: "<<endl;
    int lb = lower_bound(arr, target);
    int ub= upper_bound(arr, target);
    cout<<"Lowe bounf: indice, " <<lb<<" con valor: "<<arr[lb]<<endl;
    cout<<"Lowe bounf: indice, " <<ub<<" con valor: "<<arr[ub]<<endl;
    cout<<"cantidad de veces que aparece "<<target<<": "<<(ub-lb)<<endl; //restando indices
    return 0;
}
