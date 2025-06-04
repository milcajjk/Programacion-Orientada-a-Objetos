#include <iostream>
#include <string>

//Milca Sanchez Villalpando  

using namespace std;

class Lavadora {
private:
    enum Estado {
        APAGADA, ESPERANDO, REMOJO, ENJUAGUE, DRENAJE, SECADO
    };

    enum ModoLavado {
        NORMAL, FRAGIL, MUY_FRAGIL
    };

    Estado estado;
    ModoLavado modo;

    string obtenerNombreModo(ModoLavado m) {
        switch (m) {
            case NORMAL: return "Normal";
            case FRAGIL: return "Frágil";
            case MUY_FRAGIL: return "Muy Frágil";
            default: return "Desconocido";
        }
    }

    void esperaSimulada(int pasos) {
        cout << "Procesando";
        for (int i = 0; i < pasos; i++) {
            cout << ".";
            cout.flush();
            for (volatile long j = 0; j < 20000000; j++);
        }
        cout << " ¡Hecho!" << endl;
    }

    void mostrarInfoEstado(const string& nombre, const string& detalle = "") {
        cout << "\n[ESTADO] -> " << nombre << endl;
        if (!detalle.empty())
            cout << ">> Acción: " << detalle << endl;
        cout << ">> Modo actual: " << obtenerNombreModo(modo) << endl;
        cout << "------------------------------\n";
    }

public:
    Lavadora() : estado(APAGADA), modo(NORMAL) {}

    void activarLavadora() {
        if (estado == APAGADA) {
            estado = ESPERANDO;
            mostrarInfoEstado("ENCENDIDA", "Lavadora lista para uso.");
        } else {
            cout << "La lavadora ya está encendida.\n";
        }
    }

    void desactivarLavadora() {
        if (estado != APAGADA) {
            estado = APAGADA;
            mostrarInfoEstado("APAGADA", "Lavadora apagada.");
        } else {
            cout << "Ya está apagada.\n";
        }
    }

    void elegirModo() {
        if (estado == APAGADA) {
            cout << "Primero debe encender la lavadora.\n";
            return;
        }

        cout << "\n--- MODOS DE LAVADO ---\n";
        cout << "1. Normal\n2. Frágil\n3. Muy Frágil\nSeleccione: ";

        int opc;
        cin >> opc;

        switch (opc) {
            case 1: modo = NORMAL; break;
            case 2: modo = FRAGIL; break;
            case 3: modo = MUY_FRAGIL; break;
            default:
                cout << "Opción inválida. Se usará 'Normal' por defecto.\n";
                modo = NORMAL;
        }

        cout << "Modo seleccionado: " << obtenerNombreModo(modo) << "\n";
    }

    void cicloLavado() {
        if (estado == APAGADA) {
            cout << "Debe encender la lavadora primero.\n";
            return;
        }
        if (estado != ESPERANDO) {
            cout << "La lavadora está ocupada.\n";
            return;
        }

        cout << "\n==> Iniciando ciclo de lavado en modo " << obtenerNombreModo(modo) << "...\n";

        ejecutarRemojo();
        ejecutarEnjuague();
        ejecutarDrenaje();
        ejecutarSecado();

        estado = ESPERANDO;
        mostrarInfoEstado("CICLO TERMINADO", "La ropa está limpia.");
    }

    void verEstado() {
        cout << "\n--- ESTADO ACTUAL ---\n";
        cout << "Estado: ";
        switch (estado) {
            case APAGADA: cout << "Apagada"; break;
            case ESPERANDO: cout << "En espera"; break;
            case REMOJO: cout << "Remojando"; break;
            case ENJUAGUE: cout << "Enjuagando"; break;
            case DRENAJE: cout << "Drenando"; break;
            case SECADO: cout << "Secando"; break;
            default: cout << "Desconocido";
        }
        cout << "\nModo: " << obtenerNombreModo(modo) << endl;
        cout << "----------------------\n";
    }

private:
    void ejecutarRemojo() {
        estado = REMOJO;
        mostrarInfoEstado("REMOJO", "Llenando tambor con agua y jabón.");
        esperaSimulada(modo == NORMAL ? 5 : 2);
    }

    void ejecutarEnjuague() {
        estado = ENJUAGUE;
        mostrarInfoEstado("ENJUAGUE", "Eliminando jabón.");
        esperaSimulada(4);
    }

    void ejecutarDrenaje() {
        estado = DRENAJE;
        mostrarInfoEstado("DRENAJE", "Extrayendo agua sucia.");
        esperaSimulada(modo == MUY_FRAGIL ? 2 : 3);
    }

    void ejecutarSecado() {
        estado = SECADO;
        mostrarInfoEstado("SECADO", "Secando con centrifugado.");
        esperaSimulada(3);
    }
};

void menu() {
    cout << "\n========= MENÚ =========\n";
    cout << "1. Encender Lavadora\n";
    cout << "2. Elegir Modo de Lavado\n";
    cout << "3. Iniciar Lavado\n";
    cout << "4. Ver Estado\n";
    cout << "5. Apagar Lavadora\n";
    cout << "6. Salir\n";
    cout << "Seleccione opción: ";
}

int main() {
    Lavadora miLavadora;
    int opcion;

    cout << "=== SIMULADOR DE LAVADORA ===\n";

    do {
        menu();
        cin >> opcion;

        switch (opcion) {
            case 1: miLavadora.activarLavadora(); break;
            case 2: miLavadora.elegirModo(); break;
            case 3: miLavadora.cicloLavado(); break;
            case 4: miLavadora.verEstado(); break;
            case 5: miLavadora.desactivarLavadora(); break;
            case 6: cout << "¡Gracias por usar la lavadora!\n"; break;
            default: cout << "Opción no válida.\n"; break;
        }

        if (opcion != 6) {
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }

    } while (opcion != 6);

    return 0;
}

