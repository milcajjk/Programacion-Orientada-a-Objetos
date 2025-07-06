#include <iostream>
#include <string>
#include <fstream>

// Milca Sanchez Villalpando 
// El programa va a leer el archivo "Laberinto.txt" y mostrara en la pantalla el laberinto resuelto

using namespace std;

void muestraLaberinto();

int main() {
    muestraLaberinto();

    system("pause"); // Espere antes de finalizar (solo en Windows)
    return 0;
}

void muestraLaberinto() {
    ifstream archivoLaberinto;
    string fila;
    int contadorFilas = 0;

    archivoLaberinto.open("Laberinto.txt");

    if (!archivoLaberinto.is_open()) 
	{
        cerr << "No se puede abrir el archivo 'Laberinto.txt'" << endl;
        cerr << "Verifique que el archivo este en el mismo directorio del programa." << endl;
        exit(1);
    }

    cout << "========= LABERINTO 70x70 =========" << endl;
    cout << "Leyenda: | = paredes, _ = caminos, * = solución" << endl;
    cout << "Entrada: esquina superior izquierda" << endl;
    cout << "Salida: esquina inferior derecha" << endl << endl;

    while (getline(archivoLaberinto, fila)) {
        cout << fila << endl;
        contadorFilas++;
    }

    archivoLaberinto.close();

    cout << endl << " El Laberinto a cargado correctamente." << endl;
    cout << "Líneas totales leídas: " << contadorFilas << endl;
}
