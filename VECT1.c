#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 3

int main(){
	int i, vec[MAX];
	/* 
       Para el uso de la funci�n system(); se deber� incorporar la librer�a
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
   getch();
   return 0;
}


