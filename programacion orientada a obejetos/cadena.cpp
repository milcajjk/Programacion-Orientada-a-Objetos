#include <iostream>
#include <string>

// Milca Sanchez Villalpando

using namespace std;

// Definición de los estados posibles de la máquina de estados finitos
enum State { S1, S2, S3, S4 };

// Función que define las transiciones entre estados de acuerdo a la entrada
State transition(State current, char input) {
    switch (current) {
        case S1:
            // Desde S1: con 'a' va a S2, con 'b' va a S3
            if (input == 'a') return S2;
            if (input == 'b') return S3;
            break;
        case S2:
            // Desde S2: con 'a' permanece en S2, con 'c' va a S4
            if (input == 'a') return S2;
            if (input == 'c') return S4;
            break;
        case S3:
            // Desde S3: con 'a' va a S1, con 'b' va a S4
            if (input == 'a') return S1;
            if (input == 'b') return S4;
            break;
        case S4:
            // Desde S4: con 'd' va a S3
            if (input == 'd') return S3;
            break;
    }
    // Retorna un estado inválido si no hay transición definida
    return static_cast<State>(-1);
}

// Función auxiliar para obtener el nombre del estado en forma de cadena
string getStateName(State state) {
    switch (state) {
        case S1: return "S1";
        case S2: return "S2";
        case S3: return "S3";
        case S4: return "S4";
        default: return "ERROR";
    }
}

int main() {
    string input;

    // Solicita al usuario una cadena de entrada
    cout << "Ingresa una cadena: ";
    cin >> input;

    // El estado inicial es S1
    State current = S1;
    cout << "Estado inicial: " << getStateName(current) << endl;

    // Recorre cada carácter de la cadena y aplica las transiciones
    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];
        State next = transition(current, ch);

        // Si no hay transición válida, se termina el programa con error
        if (next == -1) {
            cout << "Error: No hay transición desde " << getStateName(current)
                 << " con entrada '" << ch << "'" << endl;
            cout << "Cadena NO aceptada." << endl;
            return 0;
        }

        // Muestra la transición realizada
        cout << "Con '" << ch << "' ? " << getStateName(next) << endl;
        current = next;
    }

    // La cadena es aceptada solo si termina en el estado S4
    if (current == S4) {
        cout << "Cadena ACEPTADA." << endl;
    } else {
        cout << "Cadena NO aceptada." << endl;
    }

    return 0;
}
