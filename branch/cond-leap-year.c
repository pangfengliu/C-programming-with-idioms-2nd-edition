#include <stdio.h>
#include <stdbool.h>
main()
{
  int year;
  scanf("%d", &year);
  bool leapYear = (year % 400 == 0)? 1 : 
   ((year % 4 == 0) && (year % 100 != 0)) ? 1 : 0;
  printf("%d\n", leapYear);
}
