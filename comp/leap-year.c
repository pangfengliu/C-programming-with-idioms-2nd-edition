#include <stdio.h>
#include <stdbool.h>

main()
{
  int year;
  scanf("%d", &year);
  bool k = (year % 400 == 0) || 
    ((year % 4 == 0) && (year % 100 != 0));
  printf("%d\n", k);
}
