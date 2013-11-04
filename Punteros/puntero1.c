#include <stdio.h>
#include <conio.h>
 
int main()
{
int num=10;
int *puntero; // Declaración de variable puntero de tipo entero
/*
Un puntero es una variable que contiene la "dirección" de memoria
de un dato en particular o de otra variable que contiene al dato.

En este caso asignamos al puntero la dirección de memoria de la
variable num
*/
puntero = &num;
 
printf("El valor de la variable num es: %d. \nEl valor del *puntero es: %d. \n",
           num,*puntero);
/* 
*puntero muestra el valor
puntero muestra la dirección de memoria
*/
printf("La direccion de memoria del *puntero es: %p",puntero);
 
getch();
return 0;
}
