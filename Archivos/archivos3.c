#include <stdio.h>

int main(){
	FILE *fp;
	char cadena[40],linea[40],*car;

	fp = fopen("archivo.txt", "r");
	
	do {
		car = fgets(linea,sizeof(linea),fp);
		if(car != NULL)
			printf("%s",linea);
		
	} while(car != NULL);
	
	
	fclose(fp);
	
	return 0;
}