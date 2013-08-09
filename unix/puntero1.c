#include <stdio.h>
#include <ncurses.h>
 
int main()
{
WINDOW *consola;
int num = 10;
int *puntero; // Declaraci�n de variable puntero de tipo entero
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
Un puntero es una variable que contiene la "direcci�n" de memoria
de un dato en particular o de otra variable que contiene al dato.

En este caso asignamos al puntero la direcci�n de memoria de la
variable num
*/
puntero = &num;
 
printw("El valor de la variable num es: %d. \nEl valor del *puntero es: %d. \n",
           num,*puntero);
/* 
*puntero muestra el valor
puntero muestra la direcci�n de memoria
*/
printw("La direccion de memoria del *puntero es: %p",puntero);
 
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
  Para compilar:  gcc puntero1.c -o puntero1 -lncurses
  (gcc archivo.c -o archivo -lncurses)
*/
