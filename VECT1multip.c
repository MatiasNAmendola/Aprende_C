#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int main(){
	int i, vec[MAX];
	/* 
       Para el uso de la función system(); se deberá incorporar la librería
	   stdlib.h
     */
    system("CLS"); // Limpia la pantalla (consola)
	for(i=0; i<=MAX; i++)
   {
   	         printf("Ingrese un numero: ");
   	         scanf("%d", &vec[i]);
   }
   for(i=0; i<=MAX; i++)
   	        printf("- %d\n", vec[i]);
   system("pause");
   return 0;
}


