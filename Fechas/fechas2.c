#include <time.h>
#include <stdio.h>

int main()
{
  time_t t,t2;
  struct tm *tm;
  char fechayhora[100];
  int seg;

  t=time(NULL);
  tm=localtime(&t);
  printf ("Hoy es: %02d/%02d/%d\n", tm->tm_mday, tm->tm_mon, 1900+tm->tm_year);
  system("PAUSE");
  t2=time(NULL);
  seg = t2 - t;
  printf("El tiempo es %d\n",seg);
}