/* date */
#include <stdio.h>
#include <stdlib.h>

struct date {
  int year;
  int month;
  int day;
}; 
typedef struct date Date;
/* compare */
int compare(const void *data1,
	    const void *data2)
{
  Date *ptr1 = (Date *)data1;
  Date *ptr2 = (Date *)data2;
  if (ptr1->year < ptr2->year)
    return -1;
  else if (ptr1->year > ptr2->year)
    return 1;
  else if (ptr1->month < ptr2->month)
    return -1;
  else if (ptr1->month > ptr2->month)
    return 1; 
  else if (ptr1->day < ptr2->day)
    return -1;
  else if (ptr1->day > ptr2->day)
    return 1;
  else 
    return 0;
}
/* main */
#define ARRAYSIZE 10
int main(void)
{
  Date array[ARRAYSIZE];
  for (int i = 0; i < ARRAYSIZE; i++) {
    scanf("%d", &(array[i].year));
    scanf("%d", &(array[i].month));
    scanf("%d", &(array[i].day));
  }
  qsort(array, ARRAYSIZE, sizeof(Date),compare);
  for (int i = 0; i < ARRAYSIZE; i++)
    printf("%d %d %d\n", array[i].year, 
	   array[i].month, array[i].day);
  return 0;
} 
/* end */
