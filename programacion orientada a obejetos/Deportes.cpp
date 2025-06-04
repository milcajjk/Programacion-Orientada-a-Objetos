#include <iostream>
#include <string>

// Milca Sanchez Villalpando

using namespace std;

// Clase base que representa un deporte gen�rico
class Deporte {
	protected:
		string nombre;
		int numeroJugadores;
		string tipoBalon;
		string lugarDeJuego;
		
	public:
		// Constructor que inicializa los atributos del deporte
		Deporte(string nombre, int jugadores, string balon, string lugar)
		: nombre(nombre), numeroJugadores(jugadores), tipoBalon(balon), lugarDeJuego(lugar) {}
		
		// M�todo virtual para mostrar la informaci�n del deporte
		virtual void mostrarInfo() {
			cout << "Nombre del deporte: " << nombre << endl;
			cout << "Numero de jugadores: " << numeroJugadores << endl;
			cout << "Tipo de bal�n: " << tipoBalon << endl;
			cout << "Lugar de juego: " << lugarDeJuego << endl;
		}
};

// Clase derivada que representa deportes que usan las manos
class DeporteConManos : public Deporte {
	private:
		string tipoDeMovimiento;
		
	public:
		// Constructor que incluye tipo de movimiento con las manos
		DeporteConManos(string nombre, int jugadores, string balon, string lugar, string movimiento)
		: Deporte(nombre, jugadores, balon, lugar), tipoDeMovimiento(movimiento) {}
		
		// Muestra la informaci�n del deporte incluyendo el tipo de movimiento
		void mostrarInfo() override {
			Deporte::mostrarInfo();
			cout << "Tipo de movimiento con las manos: " << tipoDeMovimiento << endl;
		}
};

// Clase derivada que representa deportes que usan los pies
class DeporteConPies : public Deporte {
	private:
		bool sePermiteManos;
		
	public:
		// Constructor que incluye si se permiten las manos
		DeporteConPies(string nombre, int jugadores, string balon, string lugar, bool permiteManos)
		: Deporte(nombre, jugadores, balon, lugar), sePermiteManos(permiteManos) {}
		
		// Muestra la informaci�n del deporte incluyendo si se permiten las manos
		void mostrarInfo() override {
			Deporte::mostrarInfo();
			cout << "�Se permiten las manos?: " << (sePermiteManos ? "S�" : "No") << endl;
		}
};

int main() {
	// Se crean objetos de deportes espec�ficos
	DeporteConManos basquet("Baloncesto", 5, "Bal�n de baloncesto", "Cancha", "Lanzar y botar");
	DeporteConPies futbol("F�tbol", 11, "Bal�n de f�tbol", "Campo", false);
	
	// Se muestra la informaci�n de cada deporte
	cout << "--- Deporte con manos ---" << endl;
	basquet.mostrarInfo();
	
	cout << "\n--- Deporte con pies ---" << endl;
	futbol.mostrarInfo();
	
	return 0;
}

