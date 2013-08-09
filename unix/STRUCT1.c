#include <stdio.h>
#include <ncurses.h>
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

int main(){
    WINDOW *consola;
    int i;
    jugador vect[M];
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
     
     

     for(i=0; i<M; i++)
     {
              // Clear Screen
              erase();
              // Muestra por pantalla
              printw("\nNombre del jugador: ");
              /*
                Fflush(stdin): Limpia el buffer utilizado
                por la entrada estandar, el teclado.
              */
              fflush(stdin);
              // recibe una cadena de caracteres
              gets(vect[i].nombre);
              printw("\nNombre del equipo: ");
              fflush(stdin);
              gets(vect[i].equipo);
              printw("\nCantidad de partidos jugados: ");
              scanw("%d", &vect[i].partidos);
              printw("\nCantidad de goles: ");
              scanw("%d",&vect[i].goles);
              // (float) convierte a float un valor entero
              vect[i].promedio = (float)vect[i].goles / vect[i].partidos;
     }
     erase();
     printw("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄ¿\n");
     printw("³   Nombre    ³   Equipo    ³    Goles    ³   Partidos  ³  Promedio³\n");
     printw("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄ´\n");
     /*
     %10s Deja el espacio a 10 caracteres de un array de char
          según el orden en el que se presentan las variables
     %7d  Muestra un número entero de 7 cifras.
     %.2f Muestra un número con dos decimales.
     \n   Nueva línea
     */
     for(i=0; i<M; i++)
	          printw("³%10s      ³%10s      ³%7d      ³%7d      ³     %.2f    ³\n    ",
              vect[i].nombre, vect[i].equipo, vect[i].goles, vect[i].partidos,
              vect[i].promedio);
     printw("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÙ");
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
  Para compilar:  gcc STRUCT1.c -o STRUCT1 -lncurses
  (gcc archivo.c -o archivo -lncurses)
*/
