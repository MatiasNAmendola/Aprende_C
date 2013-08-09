#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define DIEZ 10
 
int main(void){
 
    int num = 0;
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

    printf("El valor de la variable num es %d \n", num );
    printf("La direccion de memoria de la variable num es %p \n\n", &num );
    printf("La direccion de memoria siguiente a la que se encuentra la \n");
    printf("variable num es %p \n\n", &num+1 );
    printf("Y si se fijan aca, podemos ver que ciertamente 'num', que esta \n");
    printf("definida como una variable de tipo entero, esta ocupando una \n");
    printf("dimension de memoria de 4 bytes. \n");
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
      reemplazan getch(); por system("pause"); y listo!
    */
    return 0;
}
