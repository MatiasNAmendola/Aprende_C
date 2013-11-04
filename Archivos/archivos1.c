#include <stdio.h>
int main(){
	FILE *fp;
	fp = fopen ("archivo.txt", "r");
	if (fp == NULL) {
		printf("Error al abrir archivo!");
		exit(1);
	}
	fclose(fp);
	return 0;
}