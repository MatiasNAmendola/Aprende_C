#include <stdio.h>
#include <ncurses.h>
#define DIEZ 10
 
int main(void){
    WINDOW *consola;
    int num = DIEZ, res1, res2;
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
      Veamos la diferencia entre num++ y ++num en su uso y juguemos un poco con
      direcciones de memoria.
      Recordar que para mostrar una direcci�n de memoria con el printw es
      necesario utilizar %p (para el uso de punteros generalmente).
    */
    printw("El valor de la variable num es %d \n", num );
    printw("La direccion de memoria de la variable num es %p \n\n", &num );
    
    res1 = num++;
    
    printw("Si hacemos entonces res1 = num++; res1 recibe el valor %d \n",
               res1);
    printw("res1 se encuentra en la posicion de memoria %p \n", &res1 );
    /* Lo escribo en otro printw para que se pueda imprimir fisicamente */
    printw("num ahora tiene el valor %d \n", num );
    printw("Conservara la posicion de memoria num? Si, es %p \n\n", &num ); 
    num = DIEZ; /* le devolvemos a prop�sito el valor inicial a num */
    printw("Le devolvemos el valor inicial a num = %d \n\n", num );
    res2 = ++num;
    printw("Y hacemos res2 = ++num; res2 recibe asi el valor %d \n", res2 );
    printw("distinto al valor de res1 que era %d \n", res1 );
    printw("res2 se encuentra en la posicion de memoria %p \n", &res2 );      
    printw("Y num ahora tiene el valor %d \n", num );
    
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
    Para compilar:  gcc iplusoplusi.c -o iplusoplusi -lncurses
    (gcc archivo.c -o archivo -lncurses)
    
    El programa mostrar� al ejecutarse lo siguiente:
                
    El valor de la variable num es 10
    La direccion de memoria de la variable num es 0022FF44
    
    Si hacemos entonces res1 = num++; res1 recibe el valor 10
    res1 se encuentra en la posicion de memoria 0022FF40
    num ahora tiene el valor 11
    Conservara la posicion de memoria num? Si, es 0022FF44
    
    Le devolvemos el valor inicial a num = 10
    
    Y hacemos res2 = ++num; res2 recibe asi el valor 11
    distinto al valor de res1 que era 10
    res2 se encuentra en la posicion de memoria 0022FF3C
    Y num ahora tiene el valor 11

*/
