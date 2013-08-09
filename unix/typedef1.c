#include <stdio.h>
#include <ncurses.h>
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

int main(){
    WINDOW *consola;
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
     
     Persona alumno = {"Martin","Alem","M",19};
     typedef unsigned int nota;
     float promedio = 0;
     nota parcial1 = 0;
     nota parcial2 = 0;
     
     printw("\nNota del primer parcial: ");
     scanw("%d", &parcial1);
     printw("\nNota del segundo parcial: ");
     scanw("%d", &parcial2);
     promedio = (float) (parcial1 + parcial2) / 2;
     printw("\nEl alumno %7s %7s tiene como promedio: %.2f",
     alumno.nombre,alumno.apellido,promedio);
     printw("\n\nPresione una tecla para salir...");
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
  Para compilar:  gcc typedef1.c -o typedef1 -lncurses
  (gcc archivo.c -o archivo -lncurses)
*/
