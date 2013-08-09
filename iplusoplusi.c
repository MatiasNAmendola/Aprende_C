#include <stdio.h>
#include <conio.h>
#define DIEZ 10
 
int main(void){
 
    int num = DIEZ, res1, res2;
    /*
      Veamos la diferencia entre num++ y ++num en su uso y juguemos un poco con
      direcciones de memoria.
      Recordar que para mostrar una dirección de memoria con el printf es
      necesario utilizar %p (para el uso de punteros generalmente).
    */
    printf("El valor de la variable num es %d \n", num );
    printf("La direccion de memoria de la variable num es %p \n\n", &num );
    
    res1 = num++;
    
    printf("Si hacemos entonces res1 = num++; res1 recibe el valor %d \n",
               res1);
    printf("res1 se encuentra en la posicion de memoria %p \n", &res1 );
    /* Lo escribo en otro printf para que se pueda imprimir fisicamente */
    printf("num ahora tiene el valor %d \n", num );
    printf("Conservara la posicion de memoria num? Si, es %p \n\n", &num ); 
    num = DIEZ; /* le devolvemos a propósito el valor inicial a num */
    printf("Le devolvemos el valor inicial a num = %d \n\n", num );
    res2 = ++num;
    printf("Y hacemos res2 = ++num; res2 recibe asi el valor %d \n", res2 );
    printf("distinto al valor de res1 que era %d \n", res1 );
    printf("res2 se encuentra en la posicion de memoria %p \n", &res2 );      
    printf("Y num ahora tiene el valor %d \n", num );
    
    getch();
    return 0;
}
/*
    El programa mostrará al ejecutarse lo siguiente:
                
    El valor de la variable num es 10
    La direccion de memoria de la variable num es 0022FF44
    
    Si hacemos entonces res1 = num++; res1 recibe el valor 10
    res1 se encuentra en la posicion de memoria 0022FF40
    num ahora tiene el valor 11
    Conservara la posicion de memoria num? Si, es 0022FF44
    
    Le devolvemos el valor inicial a num = 10
    
    Y hacemos res2 = ++num; res2 recibe asi el valor 11
    distinto al valor de res1 que era 10
    res2 se encuentra en la posicion de memoria 0022FF3C
    Y num ahora tiene el valor 11

*/
