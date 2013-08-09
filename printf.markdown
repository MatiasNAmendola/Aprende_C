## Formateadores o especificadores de conversión utilizados en el printf ##

La función printf() permite dar formato especifico a la salida, utilizando estos tipos (formateadores):


### Enteros ###

| Formateador | Salida |
| ----------- | ------ |
| d | Lee un entero decimal opcionalmente con signo. El argumento correspondiente es un puntero a un entero (%). |
| i	| Lee un entero decimal, octal, o hexadecimal opcionalmente con signo. El argumento correspondiente es un puntero a un entero |
| o	| Lee un entero octal (en base 8) sin signo. El argumento correspondiente es un puntero a un entero sin signo |
| u	| Lee un entero decimal sin signo. El argumento correspondiente es un puntero a un entero sin signo |
| x ó X	| Lee un entero hexadecimal. El argumento correspondiente es un puntero a un entero sin signo (%x = Letras es minúscula y %X = en mayúscula. |
| h ó l	| [Prefijo] Coloca antes de cualquier especificador de conversión de enteros para indicar que la entrada de datos es un entero de tipo short o long |
| + | [Prefijo] Imprime el caracter de signo |

### Ejemplos de uso de Enteros ###

| Formateador | Salida |
| ----------- | ------ |
| %07i | justificado a la derecha, 7 digitos de largo, sin relleno |
| %.7i | largo minimo de 7 digitos, justificado a la derecha, rellena con ceros |
	
```C
#include <stdio.h>

int main(){
   int ddec, idec, ioct, ihex;
   unsigned int ooct, udec, xhex;
   short int hddec;
   long int lddec;

   printf( "Introduce un número decimal: " );
   scanf( "%d", &ddec );

   printf( "Introduce un número decimal, octal (precédelo con un cero, 0), y\n  hexadecimal (precédelo con un cero y una '\x\', 0x): " );
   scanf( "%i %i %i", &idec, &ioct, &ihex );

   printf( "Introduce un número octal: " );
   scanf( "%o", &ooct );

   printf( "Introduce un número decimal (no negativo): " );
   scanf( "%u", &udec );

   printf( "Introduce un número hexadecimal: " );
   scanf( "%x", &xhex );

   printf( "Introduce un número decimal \"pequeño\" y uno \"grande\": " );
   scanf( "%hd %ld", &hddec, &lddec );

   printf( "\nHas introducido: " );
   printf( "%d %d %d %d %d %d %d %d %d\n", ddec, idec, ioct, ihex, ooct, udec, xhex, hddec, lddec );

   return 0;
}
```

### Números de Coma Flotante ###

| Formateador | Salida |
| ----------- | ------ |
| e, E, f, g, ó G | Lee un valor de coma flotante. El argumento correspondiente es un puntero a una variable de coma flotante |
| l ó L	| [Prefijo] Coloca antes de cualquier especificador de conversión de coma flotante para indicar que la entrada de datos es un valor de tipo double o long double |

### Ejemplos de uso de Coma Flotante ###

| Formateador | Salida |
| ----------- | ------ |
| %8.2f | Tamaño total de 8 digitos, con dos decimales |
| %.2f | Flotante con dos decimales |
| %.*f”',x,d) | tamaño predeterminado, x numeros decimales |
| %*.*f”,x,y,d) | tamaño igual a x, y numeros decimales |

```C
#include <stdio.h>

int main(){
   float ereal, freal, greal;
   double lfreal;
   long double Lfreal;

   printf( "Introduce un número real: " );
   scanf( "%f", &freal );

   printf( "Introduce un número real, con exponente: " );
   scanf( "%e", &ereal );

   printf( "Introduce otro número real, con exponente: " );
   scanf( "%g", &greal );

   printf( "Introduce un número real con doble precisión y otro con mayor aún: " );
   scanf( "%lf %Lf", &lfreal, &Lfreal );

   printf( "\nHas introducido: " );
   printf( "%5.10f %5.12e %5.12g %10.20lf %10.20Lf\n", freal, ereal, greal, lfreal, Lfreal );

   return 0;
}
```

### Caracteres y Cadenas ###

| Formateador | Salida |
| ----------- | ------ |
| c	| Lee un carácter. El argumento correspondiente es un puntero a char, ningún nulo ('\0') es añadido |
| s	| Lee una cadena de caracteres. El argumento correspondiente es un puntero a una array de tipo char que es suficientemente grande para guardar la cadena y un carácter nulo ('\0') final |

### Ejemplos de Caracteres y Cadenas ###

| Formateador | Salida |
| ----------- | ------ |
| %s | cadena terminada en null |
| %5s | primeros cinco caracteres o delimitador |
| %.5s | primeros cinco caracteres, sin tener en cuenta el delimitador |
| %20.5s | primeros cinco caracteres, justificados a la derecha, con 20 caracteres de largo |
| %-20.5s | primeros cinco caracteres, justificados a la izquierda, con 20 caracteres de largo |

```C	
#include <stdio.h>
#include <string.h>

int main()
{
   char c, cadena[80];

   printf( "Introduce un carácter: " );
   scanf( "%c", &c );

   printf( "Introduce una cadena de caracteres (sin espacios): " );
   scanf( "%s", cadena );

   printf( "\nHas introducido: " );
   printf( "\'%c\' \"%s\" (%d caracteres)\n", c, cadena, strlen(cadena) );

   return 0;
}
```
	
### Conjunto de Búsqueda ###

[caracteres a buscar] Busca en una cadena de caracteres un conjunto de caracteres que están guardados en un array

Ejemplo:

```C
#include <stdio.h>
#include <string.h>
int main()
{
   char cadena[80], temp[80];

   printf( "Escribe una palabra, que empiece por una vocal: " );
   scanf( "%[aeiou]", cadena );

   scanf( "%s", temp );    /* Recoger los caracteres restantes */

   printf( "\nSólo se ha recogido las primeras letras que sean vocales: \"%s\"\n", cadena );

   printf( "Escribe otra palabra, que empiece por una consonante (no son vocales): " );
   scanf( "%[^aeiou]", cadena );

   printf( "\nSólo se ha recogido las primeras letras que no sean vocales: \"%s\"\n", cadena );

   return 0;
}
```

## Otros formateadores ##

| Formateador | Salida |
| ----------- | ------ |
| números enteros |[Prefijo] Coloca antes de un especificador para indicar la "anchura de campo" de caracteres, a la hora de asignar el valor introducido. Sólo se asignarán los primeros x caracteres especificados por el número prefijo. |
| p	| Lee un puntero de memoria de la misma forma producida cuando una dirección de memoria es convertida con %p en una sentencia de fprintf, printf, sprintf, vfprintf, vprintf, o vsprintf |
| n	| Guarda el número de caracteres entradas hasta ahora en este fscanf, scanf, o sscanf. El argumento correspondiente es un puntero a un entero. |
| %	| Salta un signo de porcentaje (%) en los datos de entrada |
| *	| [Prefijo] Símbolo de supresión de asignación. Actúa como un comodín para el dato introducido. |

```C
#include <stdio.h>

int main()
{
   int num1, num2, tam, porc;
   unsigned char cadena[10];
   unsigned int dia, mes, anyo;
   void *memPtr;

   printf( "Introduce un número de 6 dígitos: " );
   scanf( "%3d%3d", &amp;num1, &amp;num2 );
   printf( "El número introducido ha sido separado en 2 números de 3 dígitos cada uno: %d y %d\n\n", num1, num2 );

   printf( "Introduce una palabra (hasta 10 letras): " );
   scanf( "%s%n", cadena, &tam );
   printf( "La palabra escrita: \"%s\", %d caracteres escritos. Comienza en la dirección: %p\n\n", cadena, tam, cadena );

   printf( "Introduce una dirección de memoria, en hexadecimal: " );
   scanf( "%p", &memPtr );
   printf( "La memoria es: %p, y como datos tiene: %s\n\n", memPtr, memPtr );

   printf( "Introduce un porcentaje (usa el s&iacute;mbolo %%): " );
   scanf( "%d%%", &porc );
   printf( "Introdujiste: %d%%\n\n", porc );

   printf( "Introduce la fecha de hoy: " );
   scanf( "%d%*c%d%*c%d", &dia, &mes, &anyo );
   printf( "Día: %d, Mes: %d, Año: %d\n\n", dia, mes, anyo );

   return 0;
}
```
	
Más información en http://c.conclase.net/librerias/?ansifun=formato