#include <stdio.h>

main()
{
  int year[2], month[2], day[2];
  int days;

  scanf("%d", &(year[0]));
  scanf("%d", &(year[1]));
  scanf("%d", &(month[0]));
  scanf("%d", &(month[1]));
  scanf("%d", &(day[0]));
  scanf("%d", &(day[1]));
  
  days = ndays(year, month, day);
  printf("%d\n", days);
}
