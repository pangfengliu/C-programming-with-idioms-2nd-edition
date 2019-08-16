#include <stdio.h>
int *firstPositive(int *ptr)
{
  while (*ptr <= 0)
    ptr++;
  return ptr;
}
#define ARRAYSIZE 10
int main(void)
{
  int array[ARRAYSIZE];
  for (int i = 0; i < ARRAYSIZE; i++)
    scanf("%d", &(array[i]));
  int *iptr = firstPositive(array);
  printf("*iptr = %d\n", *iptr);
  printf("iptr - array = %ld\n", iptr - array);
  iptr = firstPositive(&(array[5]));
  printf("*iptr = %d\n", *iptr);
  printf("iptr - array = %ld\n", iptr - array);
  return 0;
}
