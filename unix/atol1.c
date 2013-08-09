#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
 
int main(){
    WINDOW *consola;
    char cadena[] = "1234";
    long int i;
    /*
    La funci�n initscr(); determina el tipo de terminal e inicializa todas las
    estructuras de datos privadas de la biblioteca ncurses.h
    Tambi�n hace una primera llamada a la funci�n refresh, que actualiza el
    aspecto de la pantalla. Si se produce alg�n error, imprime un mensaje
    indic�ndolo y acaba el programa. Si finaliza correctamente, devuelve un
    puntero a una estructura que hace referencia a la pantalla. Ese puntero se
    usar� como par�metro en algunas funciones.
    */
    consola = initscr();
    /*
    La funci�n savetty(); guarda el estado en que se puso en marcha el programa
    por una llamada a reset_prog_mode().
    */
	savetty();
    /*
	La funci�n keypad activa y desactiva la rutina de procesado de caracteres
    especiales. Si est� activada (el segundo par�metro es TRUE) cuando se pulse
    una tecla especial, las funciones de lectura, como getch(), devuelven un
    �nico valor, por ejemplo KEY_LEFT, para el cursor hacia arriba. 
    Si est� desactivada, la lectura de una tecla especial requiere "dos"
    caracteres, y por tanto dos lecturas, y es el usuario el que se tiene que
    encargar de interpretar los caracteres de estas teclas especiales.
	*/
	keypad(consola, TRUE);
	/*
	Las rutinas echo() y noecho() controlan si el car�cter tecleado es escrito
    en pantalla (eco) al leerse con la rutina getch.
	*/
	noecho();
	/*
	La rutinas nl() y nonl() controlan el funcionamiento de la tecla
    "retorno de carro" tanto en la lectura como en la escritura. Si se llama a 
    nonl(), la lectura del retorno de carro, no a�ade una nueva l�nea, sino que
    su funcionamiento es controlado directamente por la aplicaci�n.
    */
    nonl();
    /*
    La rutina curs_set establece el aspecto del cursor:
        0 -> invisible, 1 -> visible, 2 -> muy visible.
    */
    curs_set(0);
    /*
    Limpia la pantalla (consola)
    */
    erase();
    
    /*
      Usando printw (linux):
      %s = imprime una variable de tipo cadena (Char [n])
      %c = imprime una de tipo char
      %d � %i = imprime una de tipo int
      %.2f = imprime una de tipo float (con dos decimales)
      %li = imprime una de tipo long int
      
      la funci�n "atol" convierte una cadena en long int
      Si compilamos y ejecutamos el programa no veremos diferencias entre lo
      que tiene string = 1234 e int = 1234 , sin embargo, se trata el primero
      de una cadena y el segundo de un long int
      Para dicha funci�n o para el uso de "atoi" o "atof" es necesario incor-
      porar la librer�a stdlib.h
    */
    printw("string = %s \n", cadena );
    printw("int = %li \n", atol(cadena) );
    
    /*
      Para poder trabajar con los enteros es necesario pasar la cadena a int o
      long int o float. En este caso se pasa a "long int" y se suma a si mismo
    */
    i = atol(cadena);
    i += i;
    printw("i + i = %li\n", i);
    getch();
    echo();
    /*
    La funci�n resetty() restaura el modo de programa a partir de la �ltima
    llamada a savetty(), y se usa previo a la funci�n endwin();
    */
    resetty();
    /*
    Al terminar de trabajar en el modo terminal, el programa debe llamar a la
    funci�n endwin() para restaurar los valores apropiados de las variables de
    entorno y seguir trabajando en el modo texto normal
    */
    endwin();
    return 0;
}
/*
  Para compilar:  gcc atol1.c -o atol1 -lncurses
  (gcc archivo.c -o archivo -lncurses)
*/
