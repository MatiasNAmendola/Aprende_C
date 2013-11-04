#include <stdio.h>
#include <conio.h>
 
int main()
{
int num=10;
int *puntero; // Declaraci�n de variable puntero de tipo entero
/*
Un puntero es una variable que contiene la "direcci�n" de memoria
de un dato en particular o de otra variable que contiene al dato.

En este caso asignamos al puntero la direcci�n de memoria de la
variable num
*/
puntero = &num;
 
printf("El valor de la variable num es: %d. \nEl valor del *puntero es: %d. \n",
           num,*puntero);
/* 
*puntero muestra el valor
puntero muestra la direcci�n de memoria
*/
printf("La direccion de memoria del *puntero es: %p",puntero);
 
getch();
return 0;
}
