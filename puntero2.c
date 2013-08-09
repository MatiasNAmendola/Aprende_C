#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main() {
    /* 
       Reservamos la variable entera llamándola num ,
       inicializándola con el valor 1
       Si deseamos saber que dirección de memoria tomó num
       tan solo le anteponemos & . En este caso: &num
    */
    int num = 1;
    // Puntero a un entero
    int *ptr;
    int i;
    
    printf("Cuantos números enteros desea ingresar? ");
    scanf("%d", &num);
    /* 
       El operador sizeof devuelve el tamaño en bytes de su operando. En
       este caso devuelve el tamaño en bytes de un int (entero).
       
       En algunos compiladores podrías usarlo así
       ptr = malloc(num*sizeof(int));
       
       Lo que hacemos es crear el espacio de memoria en forma dinámica
       (con malloc) y le devolvemos la dirección (int *) de este espacio
       reservado. Acá estamos reservando de un entero multiplicado por la
       cantidad de enteros que el usuario desea.
       
       Aclaración: para usar malloc, calloc, realloc, free, rand o srand,
       entre otras, es necesario incorporar la librería stdlib.h
    */
    ptr = (int *)malloc(num*sizeof(int));
    
    // Mientras pueda reservar ese espacio de memoria
    if(ptr!=NULL) {
        for(i=0 ; i<num ; i++) {
            /* 
               Guarda los valores de i en ese espacio reservado.
               Con *(ptr+i) nos vamos corriendo en el espacio de memoria.
            */
            *(ptr+i) = i;
        }
    
        /* 
           Imprimimos los valores guardados en orden inverso al que se
           grabaron
        */
        for(i=num ; i>0 ; i--) {
            printf("%d\n", *(ptr+(i-1)));
        }
    
        free(ptr); /* Liberamos la memoria reservada */
    
        getch();
        return 0;
    }
    else {
         printf("\No hay suficiente memoria para reservar.\n");
         getch();
         return 1;
    }
}
