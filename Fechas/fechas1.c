#include <time.h>
#include <stdio.h>

int main()
{
  time_t t;
  struct tm *tm;
  char fechayhora[100];

  t=time(NULL);
  tm=localtime(&t);
  strftime(fechayhora, 100, "%d/%m/%Y", tm);
  printf ("Hoy es: %s\n", fechayhora);
}