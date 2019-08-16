#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
bool leapYear(int y)
{  
  return ((y % 400 == 0) ||
	  ((y % 4 == 0) && !(y % 100 == 0)));
}
int main(void)
{
  int year;
  scanf("%d", &year);
  assert(year > 0);
  printf("%d\n", leapYear(year));
  return 0;
}
