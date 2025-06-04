#include <stdio.h>
#include <conio.h>
#define pi 3.1416

// Milca Sanchez Villalpando

main(){
    float r;
    char opcion;

    printf("Introduzca P para el perimetro o A para el area: ");
    opcion = getch();  // Lee una tecla sin necesidad de presionar Enter

    printf("\nDame el radio: ");
    scanf("%f", &r);

    if(opcion == 'p'){  // Calcula el perímetro si se elige 'p'
        float perimetro = 2 * pi * r;
        printf("\nEl perimetro es: %.2f", perimetro);
    }
    else if(opcion == 'a'){  // Calcula el área si se elige 'a'
        float area = pi * r * r;
        printf("\nEl area es: %.2f", area);
    }

    getch();  // Espera que se presione una tecla antes de finalizar
}
