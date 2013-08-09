#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

int main() {
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
    int num = 1;
    // Puntero a un entero
    int *ptr;
    int i;
    /*
    La función initscr(); determina el tipo de terminal e inicializa todas las
    estructuras de datos privadas de la biblioteca ncurses.h
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
    
    printw("Cuantos números enteros desea ingresar? ");
    scanw("%d", &num);
    /* 
       El operador sizeof devuelve el tamaño en bytes de su operando. En
       este caso devuelve el tamaño en bytes de un int (entero).
       
       En algunos compiladores podrías usarlo así
       ptr = malloc(num*sizeof(int));
       
       Lo que hacemos es crear el espacio de memoria en forma dinámica
       (con malloc) y le devolvemos la dirección (int *) de este espacio
       reservado. Acá estamos reservando de un entero multiplicado por la
       cantidad de enteros que el usuario desea.
       
       Aclaración: para usar malloc, calloc, realloc, free, rand o srand,
       entre otras, es necesario incorporar la librería stdlib.h
    */
    ptr = (int *)malloc(num*sizeof(int));
    
    // Mientras pueda reservar ese espacio de memoria
    if(ptr!=NULL) {
        for(i=0 ; i<num ; i++) {
            /* 
               Guarda los valores de i en ese espacio reservado.
               Con *(ptr+i) nos vamos corriendo en el espacio de memoria.
            */
            *(ptr+i) = i;
        }
    
        /* 
           Imprimimos los valores guardados en orden inverso al que se
           grabaron
        */
        for(i=num ; i>0 ; i--) {
            printw("%d\n", *(ptr+(i-1)));
        }
    
        free(ptr); /* Liberamos la memoria reservada */
    
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
    else {
         printw("\No hay suficiente memoria para reservar.\n");
         getch();
         echo();
         resetty();
         endwin();
         return 1;
    }
}
/*
  Para compilar:  gcc puntero2.c -o puntero2 -lncurses
  (gcc archivo.c -o archivo -lncurses)
*/
