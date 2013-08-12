#include <stdio.h>
#include <conio.h>

int main(){
    long double doble_largo;
    double doble;
    float flotante;
    unsigned long largo_sin_signo;
    signed long largo;
    unsigned short corto_sin_signo;
    signed short corto;
    unsigned char caracter_sin_signo;
    signed char caracter;
    
    printf("En este programa aprenderemos informacion sobre las variables "
    "empleadas en C.\n\n"
    "A cada una de ellas les daremos un nombre y veremos su tama\xA4o, "
    "posicion en\nmemoria en cuanto las reservamos y su rango.\n"
    "De este modo veremos lo que 'fisicamente', o mejor dicho 'digitalmente'\n"
    "representan.\n\n"
    "Muy bien, comencemos a ver las variables que declaramos!\n\n"
    "Presione una tecla para continuar...");
    
    getch();
    system ("CLS");
    
    printf("Tipos de dato CARACTER \n\n");
    
    printf("Variable de tipo 'signed char' o simplemente 'char':\n\n"
    "El nombre que se le dio fue 'caracter'.\n"
    "Esta variable puede almacenar un valor que va desde -128 hasta +127. \n"
    "El tama\xA4o de memoria ocupado por este tipo es %x byte. \n"
    "Y la direccion de memoria en la que se encuentra es %p \n\n\n" 
    ,sizeof(caracter),&caracter);
    
    printf("Variable de tipo 'unsigned char':\n\n"
    "Nombre de la variable: caracter_sin_signo\n"
    "Puede almacenar un valor que va en el rango de 0 a +255; \n"
    "ocupa %i byte, y se encuentra en la direccion %p \n\n\n"
    ,sizeof(caracter_sin_signo),&caracter_sin_signo);
    
    printf("Presione una tecla para continuar...");
    
    getch();
    system ("CLS");
    
    printf("Tipos de dato ENTERO \n\n");
    
    printf("Variable de tipo 'signed short' o simplemente 'short':\n\n"
    "Nombre: 'corto'\n"
    "Permite almacenar un valor que va de -32.768 a +32.767; \n"
    "ocupa %i bytes, y se encuentra en la direccion %p \n\n\n"
    ,sizeof(corto),&corto);
    
    printf("Variable de tipo 'unsigned short':\n\n"
    "Nombre: 'corto_sin_signo'\n"
    "Permite almacenar un valor que va de 0 a +65.535; \n"
    "ocupa %i bytes, y se encuentra en la direccion %p \n\n\n"
    ,sizeof(corto_sin_signo),&corto_sin_signo);
    
    printf("Presione una tecla para continuar...");
    
    getch();
    system ("CLS");
    
    printf("Tipos de dato ENTERO \n\n");
    
    printf("Variable de tipo 'signed long' o simplemente long:\n\n"
    "Nombre: 'largo'\n"
    "Esta variable puede almacenar un valor que va de -2.147.483.648 a \n"
    "+2.147.483.647; \n"
    "ocupa %i bytes, y se encuentra en la direccion %p \n\n\n"
    ,sizeof(largo),&largo);
    
    printf("Variable de tipo 'unsigned long':\n\n"
    "Nombre: 'largo_sin_signo'\n"
    "Permite almacenar un valor en el rango de 0 a 4.294.967.295; \n"
    "ocupa %i bytes, y se encuentra en la direccion %p \n\n\n"
    ,sizeof(largo_sin_signo),&largo_sin_signo);
    
    printf("Presione una tecla para continuar...");
    
    getch();
    system ("CLS");
    
    printf("Tipos de dato CON COMA FLOTANTE \n\n");
    
    printf("Hasta ahora se habia podido emplear previo a definir el tipo de "
    "variable \n'unsigned' o 'signed' dependiendo de nuestra necesidad de "
    "almacenar valores \nnegativos o no.\n\nLos tipos de variables con COMA "
    "FLOTANTE no otorgan la posibilidad de decidir \nincluir o no estos "
    "valores, ya que los incorporan si o si.\nDe modo que solo debemos indicar "
    "su tipo. \n\n");
    
    printf("Presione una tecla para continuar...");
    
    getch();
    system ("CLS");
    
    printf("Tipos de dato CON COMA FLOTANTE \n\n");
    
    printf("Variable de tipo 'float':\n\n"
    "Nombre: 'flotante'\n"
    "Permite almacenar un valor que va de -3.402923E+38 a "
    "+3.402923E+38; \n"
    "ocupa %i bytes, y se encuentra en la direccion %p \n\n\n"
    ,sizeof(flotante),&flotante);
    
    printf("Variable de tipo 'double':\n\n"
    "Nombre: 'doble'\n"
    "Permite almacenar un valor que va de -1.7976931E+308 a "
    "+1.7976931E+308; \n"
    "ocupa %i bytes, y se encuentra en la direccion %p \n\n\n"
    ,sizeof(doble),&doble);
    
    printf("Variable de tipo 'long double':\n\n"
    "Nombre: 'doble_largo'\n"
    "Permite almacenar un valor que va de -1.2E+4932 a +1.2E+4932;"
    "\nocupa %i bytes, y se encuentra en la direccion %p \n\n\n"
    ,sizeof(doble_largo),&doble_largo);    

	printf("Presione una tecla para salir");
	getch();
	return 0;
}

