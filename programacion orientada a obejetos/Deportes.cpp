#include <iostream>
#include <string>

// Milca Sanchez Villalpando

using namespace std;

// Clase base que representa un deporte genérico
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
		
		// Método virtual para mostrar la información del deporte
		virtual void mostrarInfo() {
			cout << "Nombre del deporte: " << nombre << endl;
			cout << "Numero de jugadores: " << numeroJugadores << endl;
			cout << "Tipo de balón: " << tipoBalon << endl;
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
		
		// Muestra la información del deporte incluyendo el tipo de movimiento
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
		
		// Muestra la información del deporte incluyendo si se permiten las manos
		void mostrarInfo() override {
			Deporte::mostrarInfo();
			cout << "¿Se permiten las manos?: " << (sePermiteManos ? "Sí" : "No") << endl;
		}
};

int main() {
	// Se crean objetos de deportes específicos
	DeporteConManos basquet("Baloncesto", 5, "Balón de baloncesto", "Cancha", "Lanzar y botar");
	DeporteConPies futbol("Fútbol", 11, "Balón de fútbol", "Campo", false);
	
	// Se muestra la información de cada deporte
	cout << "--- Deporte con manos ---" << endl;
	basquet.mostrarInfo();
	
	cout << "\n--- Deporte con pies ---" << endl;
	futbol.mostrarInfo();
	
	return 0;
}

