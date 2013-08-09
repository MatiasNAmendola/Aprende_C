#include <stdio.h>
#include <conio.h>
/*
struct: Define una estructura que involucra a grupos de variables
typedef: sirve para alterar el nombre a un tipo de datos ya
         existen.
         
*/
typedef struct{ /* estructura anónima */
       char nombre[10],apellido[10],sexo;
       unsigned int edad;
} Persona; 
/* se declara el tipo Persona y se inicializa con un valor */

void main(){
     Persona alumno = {"Martin","Alem","M",19};
     typedef unsigned int nota;
     float promedio = 0;
     nota parcial1 = 0;
     nota parcial2 = 0;
     
     printf("\nNota del primer parcial: ");
     scanf("%d", &parcial1);
     printf("\nNota del segundo parcial: ");
     scanf("%d", &parcial2);
     promedio = (float) (parcial1 + parcial2) / 2;
     printf("\nEl alumno %7s %7s tiene como promedio: %.2f",
     alumno.nombre,alumno.apellido,promedio);
     printf("\n\nPresione una tecla para salir...");
     getch();
}
