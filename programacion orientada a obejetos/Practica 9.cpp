#include <iostream>
#include <vector>
#include <algorithm>

// Milca Sanchez Villalpando

using namespace std;

int main() {
    vector<double> numeros;
    double valor;

    cout << "Ingrese 10 valores numericos:\n";

    // Leer 10 valores del usuario
    for (int i = 0; i < 10; ++i) {
        cout << "Valor " << i + 1 << ": ";
        cin >> valor;
        numeros.push_back(valor);
    }

    // Ordenar los valores en orden ascendente
    sort(numeros.begin(), numeros.end());

    // Imprimir los valores ordenados
    cout << "\nValores ordenados:\n";
    for (size_t i = 0; i < numeros.size(); ++i) {
        cout << numeros[i] << " ";
    }

    cout << endl;
    return 0;
}


