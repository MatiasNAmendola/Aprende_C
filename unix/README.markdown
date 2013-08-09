# Biblioteca UNIX ncurses #

La librería curses y posteriormente ncurses es una librería, ideada en los inicios de UNIX,
para resolver el problema de controlar la pantalla de un terminal remoto de manera que el
texto apareciera en posiciones dadas y explotara color y capacidades del terminal particular.

La biblioteca ncurses proporciona funciones para actualizar pantallas en modo texto
independientes del terminal en entornos UNIX y GNU/Linux.

En Windows, de la mano de Borland se comenzó a utilizar la librería conio, el cual refleja sus efectos
en consola MSDOS. Sin embargo esta no aplica a terminales o consolas de varias plataformas de la
generación UNIX, por lo que resulta ideal el uso de la librería ncurses.

Curses es mucho mas rico que conio. Soporta underline (subrayar letras en la consola, ademas del clásico
 blink que las letras aparezcan y desaparezcan). La librería conio.h solo trae soporte a blink.

Curses es solo un poco mas difícil de manipular que conio.h . Esto se debe a que se puede considerar
a curses como una capa sobre la terminal, denominada ventana y sobre esta ventana se llevan a cabo los
colores y efectos de la terminal; esta ventana debe ser inicializada, al mismo tiempo que es un buffer
y debe ser tratado como tal.

## Compilado y linkado ##

Para compilar un programa que use esta biblioteca hay que incluir el fichero de cabecera ncurses.h
Para linkar un programa hay que enlazar la biblioteca libncurses.a cosa que se hace con la indicación
-lncurses el la línea de compilación (como ya se dijo antes).

## Las rutinas ##

Aunque esta biblioteca ofrece rutinas para múltiples aspectos, como manipulación de trozos de la
pantalla, rutinas de consulta del entorno, información sobre el terminal, etc., vamos a comentar las
funciones básicas necesarias para las prácticas.
Por ejemplo, se pueden definir ventanas, que son entidades lógicas que representan segmentos
independientes de la pantalla y se pueden manipular independientemente.

## Rutinas de inicialización y finalización ##

Antes de ejecutar las otras funciones de esta biblioteca es necesario llamar a las rutinas de
inicialización.

### Rutina: WINDOW *initscr(void); ###

La función initscr() determina el tipo de terminal e inicializa todas las
estructuras de datos privadas de la biblioteca. También hace una primera llamada a la función refresh,
que actualiza el aspecto de la pantalla. Si se produce algún error, imprime un mensaje indicándolo y
acaba el programa. Si finaliza correctamente, devuelve un puntero a una estructura que hace referencia
a la pantalla. Ese puntero se usará como parámetro en algunas funciones.

Ejemplo:

```C
Window *consola;
consola = initscr();
```
	
### Rutina: int savetty(void); ###

La función savetty() guarda el estado en que se puso en marcha el programa por una llamada a
reset_prog_mode().

Ejemplo:

```C
savetty();
```
	
### Rutina: int resetty(void); ###

La función resetty() restaura el modo de programa a partir de la última llamada a savetty(), y se usa
previo a la función endwin();

En realidad solo con las funciones resetty() y endwin() es suficiente. Sin embargo llamamos a la función
echo(); previamente para asegurarnos que quedara activado el "eco", de lo contrario no se verán los
caracteres, si es que en el programa hicimos un noecho();

Ejemplo:

```C
resetty();
```

### Rutina: int keypad(WINDOW *win, bool bf); ###

La rutina keypad activa y desactiva la función de procesado de caracteres especiales. Si está activada,
el segundo parámetro es true, cuando se pulse una tecla especial, las funciones de lectura, como getch(),
devuelven un único valor, por ejemplo KEY_LEFT, para el cursor hacia arriba. Si está desactivada, la 
lectura de una tecla especial requiere dos caracteres, y por tanto dos lecturas, y es el usuario el que 
se tiene que encargar de interpretar los caracteres de estas teclas especiales.

Ejemplo:

```C
keypad(consola, TRUE); // "consola" es el puntero devuelto por initscr();
```

### Rutina: int nodelay(WINDOW *win, bool bf); ###

La rutina nodelay permite activar la opción que hace que las lecturas de datos de teclado con getch() 
no sean bloqueantes. Esto quiere decir que si se hace una lectura con getch() y no hay ningún carácter
disponible en el buffer de teclado, getch acaba y devuelve como resultado el valor constante ERR.

Ejemplo: 

```C
nodelay(consola, true);  // consola es el puntero devuelto por initscr();
```

### Rutina: int noecho(void); ###

Las rutinas echo() y noecho() controlan si el carácter tecleado es escrito en pantalla (eco) al leerse
con la rutina getch();

Ejemplo:

```C
noecho();
```
	
### Rutina: int nonl(void); ###

La rutinas nl() y nonl() controlan el funcionamiento de la tecla "retorno de carro" tanto en la lectura
como en la escritura. Si se llama a nonl(), la lectura del retorno de carro, no añade una nueva línea,
sino que su funcionamiento es controlado directamente por la aplicación.

Ejemplo: 

```C
nonl();
```

### Rutina: int curs_set(int visibility); ###

La rutina curs_set establece el aspecto del cursor: 0 -> invisible, 1 -> visible, 2 -> muy visible.

### Rutina: int endwin(void); ###

Al acabar de trabajar en el modo terminal, el programa debe llamar a la rutina endwin() para restaurar
los valores apropiados de las variables de entorno y seguir trabajando en el modo texto normal.

Ejemplo:

```C
endwin();
```

## Rutinas de escritura ##

### Rutina: int move(int y, int x); ###

Este rutina mueve el cursor a la línea 'y' y la columna 'x'. Sin embargo, el cursor físico no se mueve
en el terminal hasta que se hace una llamada a la función refresh();

La posición especificada es relativa a la esquina superior izquierda de la ventana, que tiene las
coordenadas (0,0).

### Rutina: int addch(chtype ch); ###

Esta rutina escribe el carácter que se pasa como parámetro en la posición en la que esté el cursor y
avanza el cursor a la siguiente posición. El carácter no se muestra en la pantalla hasta que se hace
una llamada a la función refresh();

### Rutina: int echochar(chtype ch); ###

Esta rutina es equivalente a hacer una llamada a addch(ch) seguida de una llamada a refresh();

### Rutina: int addstr(const char cad[]); ###

Esta rutina escribe la cadena de caracteres que se pasa como parámetro en la pantalla. Es equivalenta a
llamar a addch() para cada uno de los caracteres de la cadena.

### Rutina: int printw(const char *format, ...); ###

Esta rutina permite mostrar una cadena con formato en la pantalla. Idem a printf 

### Rutina: int refresh(void); ###

La rutina refresh(); hace que se muestre la salida en la pantalla, ya que las otras funciones
simplemente manipulan estructuras de datos internas. El cursor se queda tras el último carácter escrito.

### Rutina: int erase(void); ###

La rutina erase borra la pantalla escribiendo blancos en todas las posiciones.

## Rutinas de lectura ##

### Rutina: int getch(void); ###

La rutina getch() lee un carácter del buffer de teclado. Si se está en modo de "no espera"
(ver rutina nodelay()), getch() devuelve ERR si no hay ningún valor disponible. Si se está en modo de
"espera", la rutina no acaba hasta que se pulsa algún carácter. Si el manejo de caracteres extendidos
está activado (ver rutina keypad), las teclas extendidas se leen como un solo caracter y se identifican
por un nombre que empieza por el prefijo KEY_.

Por ejemplo:
            KEY_DOWN        Los cuatro cursores
            KEY_UP          ...
            KEY_LEFT        ...
            KEY_RIGHT       ...
            KEY_HOME        Tecla Inicio
            KEY_BACKSPACE   Tecla Borrado
            KEY_F0          Teclas de función (hasta KEY_F63)

### Rutina: int getstr(char str[]); ###

Esta rutina lee una cadena de caracteres y la guarda en el parámetro.

## Otras rutinas ##

### Rutina: void getmaxyx(WINDOW *win, int y, int x); ###

getmaxyx(); devuelve el tamaño de la ventana, medido en columnas y líneas.

## Algunos enlaces con más información ##

http://www.mkssoftware.com/docs/man3/ncurses.3.asp
http://en.tldp.org/HOWTO/NCURSES-Programming-HOWTO/
http://invisible-island.net/ncurses/man/ncurses.3x.html

Ejemplo:

El siguiente programa mueve el carácter '@' por la pantalla circularmente siguiendo la pulsación
de los cursores.
El programa acaba cuando se pulsa la tecla ESC, que corresponde al carácter 27.


Para compilarlo usar 

c++ prueba_ncurses.cpp -o prueba_ncurses -lncurses


```Cpp
#include <iostream>
using namespace std;

int main(){
	WINDOW *comando;
	int tecla;
	int max_x, max_y, pos_x, pos_y;
	bool fin = false;
	comando = initscr();
	savetty();
	keypad(comando, TRUE);
	noecho();
	nonl();
	curs_set(0);
	erase();
	getmaxyx(comando, max_y, max_x);
	pos_x = max_x / 2;
	pos_y = max_y / 2;
	do {
		move(pos_y, pos_x);
		addch('@');
		refresh();

		tecla = getch();

		move(pos_y, pos_x);
		addch(' ');
		refresh();

		switch(tecla) {
		  case KEY_UP: 
			pos_y = (pos_y + (max_y - 1)) % max_y;
			break;
		  case KEY_LEFT:
			pos_x = (pos_x + (max_x - 1)) % max_x;
			break;
		  case KEY_RIGHT:
			pos_x = (pos_x + 1) % max_x;
			break;
		  case KEY_DOWN:
			pos_y = (pos_y + 1) % max_y;
			break;
		  case 27: // tecla ESC
			fin = true;
			break;
		}
	}  while (!fin);
	echo();
	resetty();
	endwin();
	return 0;
}
```
	
## Otros Ejemplos: ##

```C
#include <ncurses.h>
int main(void)
{
	char nombre[24];
	char apellido[32];
	initscr();

	addstr("¿Cual es su nombre? ");
	refresh();
	getstr(nombre);

	addstr("¿Y su apellido Sr./Sra.? ");
	refresh();
	getstr(apellido);

	printw("Encantado de conocerlo/a, %s %s!",nombre,apellido);
	refresh();
	getch();

	endwin();
	return 0;
}
```

## Ejemplo de un ejercicio con Version DOS y Conio.h , y el mismo pero acondicionado a GNU/Linux y ncurses.h ##

### Version DOS ###

```C
#include <conio.h>
#include <stdio.h>

// Prototipo de la función cuadro
int cuadro (int a,int b,int c,int d);

// Función principal
int main ()
{
	clrscr();
	cuadro(5,5,70,20);
	cuadro(6,7,69,19);

	gotoxy(15,6);
	textcolor(CYAN);
	cprintf("Bienvenido a MS/DOS");
	getchar();

	return 0;
}
int cuadro (int a,int b,int c,int d)
{
	int x;

	for (x = a; x != c; x++)
	{
		gotoxy(x,b);
		putchar(205);
	}

	for (x = b; x != d; x++)
	{
		gotoxy(c,x);
		putchar(186);
	}

	for (x = c; x != a; x–)
	{
		gotoxy(x,d);
		putchar(205);
	}

	for (x = d; x != b; x–)
	{
		gotoxy(a,x);
		putchar(186);
	}

	gotoxy(a,b);putchar(201);
	gotoxy(c,b);putchar(187);
	gotoxy(c,d);putchar(188);
	gotoxy(a,d);putchar(200);
	return 0;
}
```
	
### Version GNU/Linux ###

```C
#include <ncurses.h>
int cuadro (int a,int b,int c,int d);

int main (){
	initscr();
	savetty();
	erase();

	cuadro(5,5,70,20);
	cuadro(6,7,69,19);

	start_color();
	init_pair(1,COLOR_CYAN,COLOR_BLACK);
	attron(COLOR_PAIR (1) | A_UNDERLINE);
	
	move(6,15);
	addstr("Bienvenido a GNU/Linux");
	refresh();
	
	getch();
	echo();
	resetty();
	endwin();
	
	return 0;
}
	
int cuadro(int a,int b,int c,int d){
	int x;

	for (x = a; x != c; x++){
		move (b,x);
		addch('-');
	}
	for (x = b; x != d; x++){
		move (x,c);
		addch('|');
	}
	for (x = c; x != a; x–){
		move (d,x);
		addch('-');
	}
	for (x = d; x != b; x–){
		move (x,a);
		addch(’|');
	}
	move (b,a); addch(’+');
	move (b,c); addch(’+');
	move (d,c); addch(’+');
	move (d,a); addch(’+');
	return 0;
}
```