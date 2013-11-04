#include <stdio.h>
#include <conio.h> // Solo de Windows
#include <stdlib.h>

int main()
{
    int *lista = (int*)malloc(5*sizeof(int));
    
    int cant_num = 0, i=0;
    
    printf("Defina la cantidad de numenos a ingresar: ");
    scanf("%d",&cant_num);
    
    lista = (int*)realloc(lista,cant_num*sizeof(int));
    
    for(i=0;i<cant_num;i++)
    {
         printf("\n\nIngrese el numero %d: ",i+1);
         scanf("%d",&lista[i]);
    }
    
    for(i=0;i<cant_num;i++)
    {
         printf("%d, ",lista[i]);
    }
    printf("\n\n");
    
    free( lista );
    printf("Presione una tecla para salir...");
    getch();
    return 0;
}
