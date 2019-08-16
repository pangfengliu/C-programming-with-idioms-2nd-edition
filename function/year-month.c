#include <stdio.h>
#include <stdbool.h>

bool leapYear(int y)
{  
  return ((y % 400 == 0) || 
	  ((y % 4 == 0) && !(y % 100 == 0)));
}

int howManyDays(int year, int month)
{
  int days;
  if (year < 0 || month < 1 || month > 12)
    return 0;
  switch (month) {
    case 1: case 3: case 5: case 7: 
    case 8: case 10: case 12:
      days = 31; break;
    case 4: case 6: case 9: case 11: 
      days = 30; break;
    case 2:
      days = leapYear(year)? 29 : 28; 
      break;
    }
  return days;
}

int main(void)
{
  int year, month;
  scanf("%d%d", &year, &month);
  printf("%d\n", howManyDays(year, month));
  return 0;
}
