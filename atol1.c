#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 
int main(){
 
    char cadena[] = "1234";
    long int i;
    
    /*
      Usando printf:
      %s = imprime una variable de tipo cadena (Char [n])
      %c = imprime una de tipo char
      %d ó %i = imprime una de tipo int
      %.2f = imprime una de tipo float (con dos decimales)
      %li = imprime una de tipo long int
      
      la función "atol" convierte una cadena en long int
      Si compilamos y ejecutamos el programa no veremos diferencias entre lo
      que tiene string = 1234 e int = 1234 , sin embargo, se trata el primero
      de una cadena y el segundo de un long int
      Para dicha función o para el uso de "atoi" o "atof" es necesario incor-
      porar la librería stdlib.h
    */
    printf("string = %s \n", cadena );
    printf("int = %li \n", atol(cadena) );
    
    /*
      Para poder trabajar con los enteros es necesario pasar la cadena a int o
      long int o float. En este caso se pasa a "long int" y se suma a si mismo
    */
    i = atol(cadena);
    i += i;
    printf("i + i = %li\n", i);
    getch();
    return 0;
}
