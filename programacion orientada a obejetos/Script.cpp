#include <stdio.h>
#include <fstream>
#include <string>

// Milca Sanchez Villalpando

int main() {
    std::ifstream archivo("archivo.txt"); // Abre el archivo en modo lectura
    std::string contenido;

    if (archivo.is_open()) { // Verifica si el archivo se abrió correctamente
        std::string linea;
        while (std::getline(archivo, linea)) { // Lee línea por línea
            contenido += linea + "\n"; // Agrega la línea al contenido con salto de línea
        }
        archivo.close(); // Cierra el archivo
    } else {
        printf("No se pudo abrir el archivo.\n"); // Mensaje de error si no se abre
        return 1;
    }

    printf("Contenido del archivo:\n%s", contenido.c_str()); // Imprime el contenido leído

    return 0;
}

