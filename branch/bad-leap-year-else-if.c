#include <stdio.h>
#include <stdbool.h>
main()
{
  int year;
  bool leapYear;
  scanf("%d", &year);
  if (year % 400 != 0) 
    if ((year % 4 == 0) && (year % 100 != 0))
      leapYear = true;
    else
      leapYear = false;
  else
    leapYear = true;
  printf("%d\n", leapYear);
}
