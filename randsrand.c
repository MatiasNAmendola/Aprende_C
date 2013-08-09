#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define DIEZ 10
 
int main(void){
 
    int num = 0;
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

    printf("El valor de la variable num es %d \n", num );
    printf("La direccion de memoria de la variable num es %p \n\n", &num );
    printf("La direccion de memoria siguiente a la que se encuentra la \n");
    printf("variable num es %p \n\n", &num+1 );
    printf("Y si se fijan aca, podemos ver que ciertamente 'num', que esta \n");
    printf("definida como una variable de tipo entero, esta ocupando una \n");
    printf("dimension de memoria de 4 bytes. \n");
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
      reemplazan getch(); por system("pause"); y listo!
    */
    return 0;
}
