#include <stdio.h>
#include <fstream>
#include <string>

// Milca Sanchez Villalpando

int main() {
    std::ifstream archivo("archivo.txt"); // Abre el archivo en modo lectura
    std::string contenido;

    if (archivo.is_open()) { // Verifica si el archivo se abri� correctamente
        std::string linea;
        while (std::getline(archivo, linea)) { // Lee l�nea por l�nea
            contenido += linea + "\n"; // Agrega la l�nea al contenido con salto de l�nea
        }
        archivo.close(); // Cierra el archivo
    } else {
        printf("No se pudo abrir el archivo.\n"); // Mensaje de error si no se abre
        return 1;
    }

    printf("Contenido del archivo:\n%s", contenido.c_str()); // Imprime el contenido le�do

    return 0;
}

