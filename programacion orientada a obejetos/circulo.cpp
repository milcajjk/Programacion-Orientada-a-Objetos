#include <stdio.h>
#include <conio.h>
#define pi 3.1416



main(){
	float r;
	char opcion;
	
	printf("Introduzca P para el perimetro o A para el area: ");
	opcion = getch();
	
	printf("\nIntroduzca el radio: ");
	scanf("%f", &r);
	
	if(opcion == 'p'){
		float perimetro = 2 * pi * r;
		printf("\nEl perimetro es: %.2f", perimetro);
	}
	
	else if(opcion == 'a'){
		float area = pi * r * r;
		printf("\nEl area es: %.2f", area);
	}
	getch();
}
