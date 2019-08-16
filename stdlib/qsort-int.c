#include <stdio.h>
#include <stdlib.h>
int compare(const void *data1,
	    const void *data2)
{
  int *ptr1 = (int *)data1;
  int *ptr2 = (int *)data2;
  if (*ptr1 < *ptr2)
    return -1;
  else if (*ptr1 > *ptr2)
    return 1;
  else
    return 0;
}
#define ARRAYSIZE 10
int main(void)
{
  int array[ARRAYSIZE];
  for (int i = 0; i < 10; i++)
    scanf("%d", &(array[i]));
  qsort(array, ARRAYSIZE, sizeof(int), compare);
  for (int i = 0; i < ARRAYSIZE; i++)
    printf("%d ", array[i]);
  return 0;
}
