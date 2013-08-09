#include <stdio.h>
#include <conio.h>
// Define una constante
#define M 2
/*
struct: Define una estructura que involucra a grupos de variables
typedef: sirve para alterar el nombre a un tipo de datos ya
         existen.
         
*/
typedef struct{
       char nombre[10],equipo[10];
       int partidos,goles;
       float promedio;
} jugador;

void main(){
     int i;
     jugador vect[M];

     for(i=0; i<M; i++)
     {
              // Clear Screen
              system("CLS");
              // Muestra por pantalla
              printf("\nNombre del jugador: ");
              /*
                Fflush(stdin): Limpia el buffer utilizado
                por la entrada estandar, el teclado.
              */
              fflush(stdin);
              // recibe una cadena de caracteres
              gets(vect[i].nombre);
              printf("\nNombre del equipo: ");
              fflush(stdin);
              gets(vect[i].equipo);
              printf("\nCantidad de partidos jugados: ");
              scanf("%d", &vect[i].partidos);
              printf("\nCantidad de goles: ");
              scanf("%d",&vect[i].goles);
              // (float) convierte a float un valor entero
              vect[i].promedio = (float)vect[i].goles / vect[i].partidos;
     }
     system("CLS");
     printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄ¿\n");
     printf("³   Nombre    ³   Equipo    ³    Goles    ³   Partidos  ³  Promedio³\n");
     printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄ´\n");
     /*
     %10s Deja el espacio a 10 caracteres de un array de char
          según el orden en el que se presentan las variables
     %7d  Muestra un número entero de 7 cifras.
     %.2f Muestra un número con dos decimales.
     \n   Nueva línea
     */
     for(i=0; i<M; i++)
	          printf("³%10s      ³%10s      ³%7d      ³%7d      ³     %.2f    ³\n    ",
              vect[i].nombre, vect[i].equipo, vect[i].goles, vect[i].partidos,
              vect[i].promedio);
     printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÙ");
     getch();
}
