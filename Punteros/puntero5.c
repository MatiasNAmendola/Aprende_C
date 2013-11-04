#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct datos_carnet
{
    long int numero;
    char letra;
    char nombre[50];
    char apellido[100];
};

struct datos_carnet dni;

void escribir_dni(struct datos_carnet dni);
void escribir_dni(struct datos_carnet* dni);



int main()
{
    char** nombre;
    char* nombre2="pepe";
    nombre = &nombre2;
    
    printf("*nombre = %p\n",*nombre);
    printf("nombre = %s\n",nombre);
    printf("nombre2 = %s\n",nombre2);
    
    nombre[0] = nombre2;
    
    printf("nombre = %s\n",nombre[0]);
    //printf("nombre2 = %s\n",nombre2);
    
    printf("Escriba el nombre: ");
    fflush(stdin);
    scanf("%s",dni.nombre);
    printf("Escriba el apellido: ");
    fflush(stdin);
    scanf("%s",dni.apellido);  
}