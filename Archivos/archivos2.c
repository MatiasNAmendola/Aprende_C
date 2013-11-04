#include <stdio.h>

int main(){
	FILE *fp;
	char cadena[40];
	int i=1;
	fp = fopen("archivo.txt", "a+");
	
	printf("Ingrese una cadena: ");
	
	gets(cadena);
	
	fprintf(fp,"\n%s\n",cadena);

	fclose(fp);
	
	return 0;
}