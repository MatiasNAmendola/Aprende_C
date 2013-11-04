#include <stdio.h>
#include <conio.h>
#include <stdlib.h>



int main()
{
    /* int variable = 4;
    
    int *puntero_variable;
    
    puntero_variable = &variable; // Le pasas la direccion de memoria con el &
    
    */
    int *puntero_arreglo, arreglo[3], i;
    
    puntero_arreglo = arreglo;
    
    arreglo[0] = 25;
    arreglo[1] = 60;
    arreglo[2] = 2;
    
    // Lo
    for (i=0; i<3; i++)
        printf("Valor 1: %d\n",*(puntero_arreglo+i));
        
    for (i=0; i<3; i++)
        printf("Valor 1: %d\n",puntero_arreglo[i]);
    
    for (i=0; i<3; i++)
        printf("Valor 1: %d\n",arreglo[i]);
        
    printf("Valor del puntero: %d",*puntero_arreglo);
        
    getch();
}

