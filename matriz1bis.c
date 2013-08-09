#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX_FILA 6
#define MAX_COLUMNA 5


void main (){

     int mat[MAX_FILA][MAX_COLUMNA], i, j;

     system ("CLS"); // Clear Screen
     
     /*
       i<MAX_FILA y j<MAX_COLUMNA se aplican a los for como condiciones de 
       corte ya que en realidad los valores de las contantes están pensadas 
       para MAX_FILA (6) : que va de 0 a 5, 
       y MAX_COLUMNA (5) : va de 0 a 4.
     */
       
     for(i=0; i<MAX_FILA; i++)
              for(j=0; j<MAX_COLUMNA; j++)
                	mat[i][j]=0;
     
     do {          	
        printf("\nIngrese el n£mero de fila (de 1 a %d): ",MAX_FILA);
        scanf("%d", &i);
        if ( i<1 || i>MAX_FILA ){
           printf("\nN£mero incorrecto");
           getch();
           system ("CLS");
        }
     } while( i<1 || i>MAX_FILA );
     
     system ("CLS");
     
     do {          	
        printf("\nIngrese el n£mero de columna (de 1 a %d): ",MAX_COLUMNA);
        scanf("%d", &j);
        if ( j<1 || j>MAX_COLUMNA ){
           printf("\nN£mero incorrecto");
           getch();
           system ("CLS");
        }
     } while( j<1 || j>MAX_COLUMNA );
     
     system ("CLS");
     
     printf("\nIngrese un n£mero entero: ");
     scanf("%d", &mat[i-1][j-1]);
     
     system ("CLS");
     printf("\n\t\t\t\t  Matriz\n\n\n\n\t\t\t\t");
     for(i=0; i<6; i++){
	      if(i!=0)
	          printf("\n\n\t\t\t\t");
          for(j=0; j<5; j++)
              printf(" %d", mat[i][j]);
	}
	printf("\n");
    getch();
}


