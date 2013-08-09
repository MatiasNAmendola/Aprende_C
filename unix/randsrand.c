#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#define DIEZ 10
 
int main(void){
    WINDOW *consola;
    int num = 0;
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
      Cada vez que se invoque la función 'rand()', ésta genera un número 
      pseudo-aleatorio entre 0 y 'RAND_MAX', la cual es una constante 
      definida en la librería que necesitamos que es stdlib. Esta generación
      de números realmente sigue una 'fórmula' la cual crea varios números
      enteros en una serie. Para comenzar una serie u otra, invocamos 'srand()'
      la cual "planta un valor semilla" el cual comienza la generación de
      números pseudo-aleatorios. Para ofrecer algo más de aleatoriedad, se
      sugiere que como valor semilla se pase la fecha y hora cada vez que se
      ejecute. Esto se puede hacer invocando la función 'time()', la cual
      requiere incorporar una librería más que es time.h del mismo modo que
      se incluyeron las otras librerías.
      
      Aclaración y precaución más que nada: sólo se debe invocar 'srand()' una
      vez en nuestro programa, luego para aplicarlo se usa rand() solo. srand()
      no devuelve ningún valor, el que lo hace es la función rand(). Y a la
      función 'srand()' no es necesario que usen time(0) o time(NULL), pueden
      utilizar el valor que deseen.
    */
    srand(time(0)); // Puede ponerse también srand(time(NULL));
    num = rand();

    printw("El valor de la variable num es %d \n", num );
    printw("La direccion de memoria de la variable num es %p \n\n", &num );
    printw("La direccion de memoria siguiente a la que se encuentra la \n");
    printw("variable num es %p \n\n", &num+1 );
    printw("Y si se fijan aca, podemos ver que ciertamente 'num', que esta \n");
    printw("definida como una variable de tipo entero, esta ocupando una \n");
    printw("dimension de memoria de 4 bytes. \n");
    /*
      Compilen y ejecuten varias veces el programa para ver los valores que va
      adquiriendo la variable num, y vean también la diferencia en el valor que
      devuelve rand() si no se aplica la función srand(time(0)); (conviertanla
      en un comentario momentáneamente.
    */
    getch();
    /*
      Otra aclaración con el uso de getch(); para "pausar" de alguna manera al
      programa ya que puede no funcionar en ciertas ocaciones dependiendo del
      sistema anfitrión que se use, es el de que se puede reemplazar por la 
      función con el argumento o parámetro: system("pause"); teniendo en
      cuenta el incorporar la librería stdlib.h para su funcionamiento. Asique
      reemplazan getch(); por system("pause"); y listo! (esto en
      el caso de Windows). En el caso de Linux para hacer funcionar a getch();
      es necesario incorporar otra librería, la llamada: ncurses.h
    */
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
  Para compilar:  gcc randsrand.c -o randsrand -lncurses
  (gcc archivo.c -o archivo -lncurses)
*/
