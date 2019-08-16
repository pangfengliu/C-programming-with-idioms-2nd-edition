#include <stdio.h>
#include <stdbool.h>

main()
{
  int year;
  scanf("%d", &year);
  bool leapYear;
  if (year % 400 == 0) 
    leapYear = true;
  else if ((year % 4 == 0) && (year % 100 != 0))
    leapYear = true;
  else
    leapYear = false;
  printf("%d\n", leapYear);
}
