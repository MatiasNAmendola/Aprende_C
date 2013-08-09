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
     printw("������������������������������������������������������������������Ŀ\n");
     printw("�   Nombre    �   Equipo    �    Goles    �   Partidos  �  Promedio�\n");
     printw("������������������������������������������������������������������Ĵ\n");
     /*
     %10s Deja el espacio a 10 caracteres de un array de char
          seg�n el orden en el que se presentan las variables
     %7d  Muestra un n�mero entero de 7 cifras.
     %.2f Muestra un n�mero con dos decimales.
     \n   Nueva l�nea
     */
     for(i=0; i<M; i++)
	          printw("�%10s      �%10s      �%7d      �%7d      �     %.2f    �\n    ",
              vect[i].nombre, vect[i].equipo, vect[i].goles, vect[i].partidos,
              vect[i].promedio);
     printw("����������������������������������������������������������������������");
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
  Para compilar:  gcc STRUCT1.c -o STRUCT1 -lncurses
  (gcc archivo.c -o archivo -lncurses)
*/
