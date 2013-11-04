#include <stdio.h>
#include <conio.h>
#include <string.h>

int agregar_informacion(FILE *documento,char informacion[]);



int main()
{
    char rutadoc[] = "C:\\nuevaaaaa.txt";
    FILE *documento;
    // Recibe dos parametros: 1- Nombre del archivo, 2-Modo de apertura
    documento = (FILE *)fopen(rutadoc,"a+");
    
    
    
    if(documento == NULL)
    {
         printf("Error con el documento\n\n");
         
	} else {
         
         fprintf(documento,"\nEsta es una prueba de \nguardado de un documento");
         fclose(documento);    
    }
    printf("Presione una tecla para salir...");
    getch();
    return 0;
}


int agregar_informacion(FILE *documento,char informacion[])
{
    documento = (FILE *)fopen(rutadoc,"a+");
    if(documento == NULL)
    {
        printf("Error con el documento\n\n");
        return -1;
    }
    fprintf(documento,"%s\n",informacion);
    fclose(documento);
    return 0;
}