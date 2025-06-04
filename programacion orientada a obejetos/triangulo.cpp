#include <iostream>

// Milca Sanchez Villalpando

using namespace std;

int main() {
    float lado1, lado2, lado3;

    // Solicita los lados del triángulo al usuario
    cout << "Ingrese el primer lado del triangulo: ";
    cin >> lado1;
    cout << "Ingrese el segundo lado del triangulo: ";
    cin >> lado2;
    cout << "Ingrese el tercer lado del triangulo: ";
    cin >> lado3;

    // Verifica si los lados forman un triángulo válido
    if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1) {
        // Clasifica el triángulo según sus lados
        if (lado1 == lado2 && lado2 == lado3) {
            cout << "El triángulo es equilatero." << endl;
        } else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
            cout << "El triangulo es isosceles." << endl;
        } else {
            cout << "El triangulo es escaleno." << endl;
        }
    } else {
        // Si no cumple con la desigualdad triangular
        cout << "Los lados no forman un triangulo valido." << endl;
    }

    return 0;
}

