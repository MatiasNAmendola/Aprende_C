#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#define DIEZ 10
 
int main(void){
    WINDOW *consola;
    int num = 0;
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
      Cada vez que se invoque la funci�n 'rand()', �sta genera un n�mero 
      pseudo-aleatorio entre 0 y 'RAND_MAX', la cual es una constante 
      definida en la librer�a que necesitamos que es stdlib. Esta generaci�n
      de n�meros realmente sigue una 'f�rmula' la cual crea varios n�meros
      enteros en una serie. Para comenzar una serie u otra, invocamos 'srand()'
      la cual "planta un valor semilla" el cual comienza la generaci�n de
      n�meros pseudo-aleatorios. Para ofrecer algo m�s de aleatoriedad, se
      sugiere que como valor semilla se pase la fecha y hora cada vez que se
      ejecute. Esto se puede hacer invocando la funci�n 'time()', la cual
      requiere incorporar una librer�a m�s que es time.h del mismo modo que
      se incluyeron las otras librer�as.
      
      Aclaraci�n y precauci�n m�s que nada: s�lo se debe invocar 'srand()' una
      vez en nuestro programa, luego para aplicarlo se usa rand() solo. srand()
      no devuelve ning�n valor, el que lo hace es la funci�n rand(). Y a la
      funci�n 'srand()' no es necesario que usen time(0) o time(NULL), pueden
      utilizar el valor que deseen.
    */
    srand(time(0)); // Puede ponerse tambi�n srand(time(NULL));
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
      adquiriendo la variable num, y vean tambi�n la diferencia en el valor que
      devuelve rand() si no se aplica la funci�n srand(time(0)); (conviertanla
      en un comentario moment�neamente.
    */
    getch();
    /*
      Otra aclaraci�n con el uso de getch(); para "pausar" de alguna manera al
      programa ya que puede no funcionar en ciertas ocaciones dependiendo del
      sistema anfitri�n que se use, es el de que se puede reemplazar por la 
      funci�n con el argumento o par�metro: system("pause"); teniendo en
      cuenta el incorporar la librer�a stdlib.h para su funcionamiento. Asique
      reemplazan getch(); por system("pause"); y listo! (esto en
      el caso de Windows). En el caso de Linux para hacer funcionar a getch();
      es necesario incorporar otra librer�a, la llamada: ncurses.h
    */
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
  Para compilar:  gcc randsrand.c -o randsrand -lncurses
  (gcc archivo.c -o archivo -lncurses)
*/
