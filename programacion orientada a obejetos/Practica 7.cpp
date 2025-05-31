#include <iostream>
#include <cmath> // funci�n pow()
#include <iomanip> //  formatear la salida

using namespace std;

int main() {
    const double deposito_mensual = 1000.0;
    const double tasa_interes_mensual = 0.03; // 3%
    const int anios = 10;
    const int meses = anios * 12;
    
    double valor_futuro = 0.0;
    
    // M�todo 1: Usando la f�rmula matem�tica directa
    valor_futuro = deposito_mensual * ( (pow(1 + tasa_interes_mensual, meses) - 1) / tasa_interes_mensual );
    
    cout << fixed << setprecision(2); // Formato para mostrar 2 decimales
    cout << "Metodo 1 (Formula directa):" << endl;
    cout << "Despues de " << anios << " a�os, tendras ahorrado: $" << valor_futuro << endl;
    
    // M�todo 2: Calculando mes por mes (simulaci�n)
    double ahorro = 0.0;
    for (int mes = 1; mes <= meses; ++mes) {
        ahorro += deposito_mensual;
        ahorro *= (1 + tasa_interes_mensual);
    }
    
    cout << "\nMetodo 2 (Simulacion mes a mes):" << endl;
    cout << "Despues de " << anios << " a�os, tendras ahorrado: $" << ahorro << endl;
    
    return 0;
}

