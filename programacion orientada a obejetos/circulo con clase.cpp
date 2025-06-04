#include <conio.h>
#include <stdio.h>
#define pi 3.1416

// Milca Sanchez Villalpando

// Definici�n de la clase circulo
class circulo {
	private:
		float radio;
	
	public:
		// Constructor que inicializa el radio
		circulo(float r) : radio(r) {}

		// Calcula el per�metro del c�rculo
		float calcularPerimetro() {
			return 2 * pi * radio;
		}
		
		// Calcula el �rea del c�rculo
		float calcularArea() {
			return pi * radio * radio;
		}
		
		// Establece un nuevo valor para el radio
		void setRadio(float r) {
			radio = r;
		}
		
		// Devuelve el valor del radio
		float getRadio() {
			return radio;
		}
};

main()
{
	float radio;
	char opcion;

	// Solicita al usuario la opci�n deseada
	printf("Introdusca P para el perimetro o A para el area: ");
	opcion = getch();
	
	// Solicita el valor del radio
	printf("\nDame el radio: ");
	scanf("%f", &radio);
	
	circulo miCirculo(radio);
	
	// Verifica la opci�n ingresada y muestra el resultado correspondiente
	if(opcion == 'p'){
		printf("\nEl perimetro es: %.2f", miCirculo.calcularPerimetro());
	}
	else if(opcion == 'a'){
		printf("\nEl area es: %.2f", miCirculo.calcularArea());
	}

	getch();	
}

