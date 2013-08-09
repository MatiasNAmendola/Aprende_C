#include <stdio.h>

int main()
{
   char oracion[81];

   // Muestra por pantalla
   printf( "Escribe una oracion:\n");
   // gets: Recibe y retorna una cadena de caracteres
   printf( "\nHas escrito: \"%s\"\n", gets(oracion) ); 

   /*
   Getchar() o getch() va a pausar la ejecucion de tu programa para
   esperar el ingreso de un caracter por la entrada estandar del
   sistema, en este caso, el teclado.
   */
   getch();
   return 0;
}
