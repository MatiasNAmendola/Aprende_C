#include <stdio.h>
#include <conio.h>
#define MAX_ARRAY 5

// Prototipos

// Por valores
int sumar(int a,int b);
// Por referencia
void sumar1(int *a);

void cargar_array(int *array);

void duplicar_array(int array[]);

int contar_array(int *array);

int main()
{
    int num1=45,num2=12,cont=0;
    int vector[MAX_ARRAY];
    printf("Sumar %d + %d = %d\n\n",num1,num2,sumar(num1,num2));
    printf("Sumar1 %d = ",num1);
    sumar1(&num1);
    printf("%d\n\n",num1);
    cargar_array((int*)vector);
    cont=contar_array((int*)vector);
    printf("El total da %d\n\n",cont);
    duplicar_array(vector);
    cont=contar_array((int*)vector);
    printf("El total da %d\n\n",cont);
    getch();
    return 0;
}
int sumar(int a,int b)
{
    return a+b;
}
void sumar1(int *a)
{
    (*a)++;
}
void cargar_array(int *array)
{
    int i=0;
    for(i=0;i<MAX_ARRAY;i++)
    {
         array[i]=i;
    } 
     
}
void duplicar_array(int array[])
{
     int i=0;
    for(i=0;i<MAX_ARRAY;i++)
    {
         array[i] += array[i];
    } 
     
}
int contar_array(int *array)
{
    int i=0,cont=0;
    for(i=0;i<MAX_ARRAY;i++)
    {
         cont += array[i];
    }
    return cont; 
}