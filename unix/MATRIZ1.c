#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#define MAX_FILA 6
#define MAX_COLUMNA 5


int main (){
    WINDOW *consola;
    int mat[MAX_FILA][MAX_COLUMNA], i, j;
     /*
    La función initscr(); determina el tipo de terminal e inicializa todas las
    estructuras de datos privadas de la biblioteca ncurses.h
    También hace una primera llamada a la función refresh, que actualiza el
    aspecto de la pantalla. Si se produce algún error, imprime un mensaje
    indicándolo y acaba el programa. Si finaliza correctamente, devuelve un
    puntero a una estructura que hace referencia a la pantalla. Ese puntero se
    usará como parámetro en algunas funciones.
    */
     consola = initscr();
     /*
    La función savetty(); guarda el estado en que se puso en marcha el programa
    por una llamada a reset_prog_mode().
    */
	savetty();
     /*
	La función keypad activa y desactiva la rutina de procesado de caracteres
    especiales. Si está activada (el segundo parámetro es TRUE) cuando se pulse
    una tecla especial, las funciones de lectura, como getch(), devuelven un
    único valor, por ejemplo KEY_LEFT, para el cursor hacia arriba. 
    Si está desactivada, la lectura de una tecla especial requiere "dos"
    caracteres, y por tanto dos lecturas, y es el usuario el que se tiene que
    encargar de interpretar los caracteres de estas teclas especiales.
	*/
	keypad(consola, TRUE);
	/*
	Las rutinas echo() y noecho() controlan si el carácter tecleado es escrito
    en pantalla (eco) al leerse con la rutina getch.
	*/
	noecho();
	/*
	La rutinas nl() y nonl() controlan el funcionamiento de la tecla
    "retorno de carro" tanto en la lectura como en la escritura. Si se llama a 
    nonl(), la lectura del retorno de carro, no añade una nueva línea, sino que
    su funcionamiento es controlado directamente por la aplicación.
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
       i<MAX_FILA y j<MAX_COLUMNA se aplican a los for como condiciones de 
       corte ya que en realidad los valores de las contantes están pensadas 
       para MAX_FILA (6) : que va de 0 a 5, 
       y MAX_COLUMNA (5) : va de 0 a 4.
     */
       
     for(i=0; i<MAX_FILA; i++)
              for(j=0; j<MAX_COLUMNA; j++)
                	mat[i][j]=0;
                	
     printw("\nIngrese el n£mero de fila (de 1 a 6): ");
     scanw("%d", &i);
     printw("\nIngrese el n£mero de columna (de 1 a 5): ");
     scanw("%d", &j);
     printw("\nIngrese un n£mero entero: ");
     scanw("%d", &mat[i-1][j-1]);
     
     erase();
     printw("\n\t\t\t\t  Matriz\n\n\n\n\t\t\t\t");
     for(i=0; i<6; i++){
	      if(i!=0)
	          printw("\n\n\t\t\t\t");
          for(j=0; j<5; j++)
              printw(" %d", mat[i][j]);
	}
    getch();
    echo();
    /*
    La función resetty() restaura el modo de programa a partir de la última
    llamada a savetty(), y se usa previo a la función endwin();
    */
    resetty();
    /*
    Al terminar de trabajar en el modo terminal, el programa debe llamar a la
    función endwin() para restaurar los valores apropiados de las variables de
    entorno y seguir trabajando en el modo texto normal
    */
    endwin();
    return 0;
}
/*
  Para compilar:  gcc MATRIZ1.c -o MATRIZ1 -lncurses
  (gcc archivo.c -o archivo -lncurses)
*/

