#include <time.h>
#include <stdio.h>

int main()
{
  time_t t;
  struct tm *tm;
  char fechayhora[100];
  char *meses[12]={"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
  	  	  	  	  "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre",
				"Diciembre"};

  t=time(NULL);
  tm=localtime(&t);
  printf ("Hoy es: %02d/%s/%d\n", tm->tm_mday, meses[tm->tm_mon],
  	  	  	  1900+tm->tm_year);
}