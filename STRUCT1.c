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
     printf("������������������������������������������������������������������Ŀ\n");
     printf("�   Nombre    �   Equipo    �    Goles    �   Partidos  �  Promedio�\n");
     printf("������������������������������������������������������������������Ĵ\n");
     /*
     %10s Deja el espacio a 10 caracteres de un array de char
          seg�n el orden en el que se presentan las variables
     %7d  Muestra un n�mero entero de 7 cifras.
     %.2f Muestra un n�mero con dos decimales.
     \n   Nueva l�nea
     */
     for(i=0; i<M; i++)
	          printf("�%10s      �%10s      �%7d      �%7d      �     %.2f    �\n    ",
              vect[i].nombre, vect[i].equipo, vect[i].goles, vect[i].partidos,
              vect[i].promedio);
     printf("����������������������������������������������������������������������");
     getch();
}
