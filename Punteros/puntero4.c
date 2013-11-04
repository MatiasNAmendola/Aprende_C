#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(){
    // Declaraciónes de Variables:
    // Variable
    int numero = 6;
    // Variable de tipo puntero
    int *puntero;
    puntero = &numero; // Le estoy pasando la dirección de memoria, no su valor
    
    printf("El valor de la variable numero es: %d\n\n",numero);
    printf("El valor de la variable puntero es: %d\n\n",*puntero);
    
    // Ahora le cambio el valor a numero
    numero = 475;
    
    printf("Le asigno a numero = 475\n\n");
    printf("El valor de la variable numero es: %d\n\n",numero);
    printf("El valor de la variable puntero es: %d\n\n",*puntero);
    
    
    
    printf("Ingrese una tecla para salir...");
    getch();
    return 0;
}
