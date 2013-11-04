#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct nodo {
	int dato;
	struct nodo *sig;
}; typedef struct nodo NODO;

// --- Esto no era necesario
int contarNodos(NODO *p);

int main()
{
	
	NODO *lista;
	int cant_nodos;
	
	// Definimos el tamaño que va a tener nuestra lista
	// En este caso tendra 3 nodos
	lista = (NODO *)malloc(3*sizeof(NODO));
	
	// Creamos basicamente una lista (en forma sencilla)
	lista[0].dato = 5;
	lista[0].sig = &lista[1];
	lista[1].dato = 2;
	lista[1].sig = &lista[2];
	lista[2].dato = 4;
	lista[2].sig = NULL;
	
	// Llamamos a la funcion que cuenta la cantidad de nodos
	cant_nodos = contarNodos(lista);
	
	printf("La cantidad de nodos es: %d \n",cant_nodos);
	
	/*
	Liberamos el espacio que utilizamos para almacenar
	la lista. 
	Esta practica es muy recomendada a la hora de reservar
	memoria en forma dinamica.
	*/
	free(lista);
	printf("Presione una tecla para salir...");
	getch();
	return 0;	
}
// --- (fin) Esto no era necesario

int contarNodos(NODO *p)
{
	// Inicializamos el contador
	int contador = 0;
	
	/*
	Creamos un puntero de igual formato al
	puntero que recibimos como parametro,
	para no perder la direccion inicial y de
	este modo poder utilizarlo para otros
	procesos, funciones, etc.
	*/
	NODO *x;	
	x = p;
	/*
	Mientras que el nodo sucesor no sea NULL
	contara el numero de nodos perteneciente
	a la lista.
	*/
	while (x != NULL)
	{
		contador++;
		x = x->sig;
	}
	return contador;	
}