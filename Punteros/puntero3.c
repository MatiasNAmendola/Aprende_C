#include <stdio.h>
#include <conio.h>
#include <stdlib.h>



int main()
{
    
    int numero = 6;
    int *numeros;
    float flotante = 9.7;
    int *valor;
    valor = &numero;
    int variable2;
    variable2 = *valor; // variable2 = numero;
    numero = 7;
    
    printf("la variable numero tiene como valor: %d\n\n",numero);
    printf("el dato que tiene valor es: %d\n\n",*valor);
    printf("variable2 tiene el valor: %d\n\n",variable2);
    printf("la posicion en la memoria en donde se encuentra numero es: %p\n\n",
               &numero);
    printf("La posicion de memoria que guarda valor es %p\n\n",valor);
    printf("la posicion en la memoria en donde se encuentra flotante es: %p\n\n",
               &flotante);        
    numero = (int)flotante;
    
    numeros = (int *)malloc(5*sizeof(int));
    
    numeros[0] = 6;
    
    printf("El tamaño de la variable numero es: %d\n\n",5*sizeof(numero));
    
    printf("Ahora numero tiene guardado: %d\n\n",numero);
    printf("el dato que tiene valor es: %d\n\n",*valor);
    printf("El puntero valor tiene como valor: %d\n\n",valor);
    
    printf("En la variable apuntada a numeros, en su primera posicion es: %d\n\n",
               numeros[0]);
    
    numero = 400;
    printf("Ahora numero tiene guardado: %d\n\n",numero);
    printf("el dato que tiene valor es: %d\n\n",*valor);
    
    free(numeros);
    printf("Presione una tecla para salir...");
    getch();
    return 0;
}
