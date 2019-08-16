#include <stdio.h>

void printArray(int array[], int n)
{
  for (int i = 0; i < n; i++)
    printf("a[%d] = %d\n", i, array[i]);
  return;
}

void incArray(int array[], int n)
{
  printf("incArray: array = %p\n", array);
  for (int i = 0; i < n; i++)
    array[i]++;
  return;
}

#define ASIZE 5

int main(void)
{
  int a[ASIZE];
  for (int i = 0; i < ASIZE; i++)
    scanf("%d", &(a[i]));

  printf("before incArray\n");
  printArray(a, ASIZE);

  incArray(a, ASIZE);
  printf("after first incArray\n");
  printArray(a, ASIZE);

  incArray(&(a[1]), 2);
  printf("after second incArray\n");
  printArray(a, 5);

  incArray(&(a[2]), 2);
  printf("after second incArray\n");
  printArray(a, ASIZE);
  return 0;
}
