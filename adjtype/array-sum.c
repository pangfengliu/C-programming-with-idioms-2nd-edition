#include <stdio.h>

int sum(const int a[], const int n)
{
  int total = 0;
  for (int i = 0; i < n; i++)
    total += a[i];
  return total;
}
#define ARRAYSIZE 5
int main(void)
{
  int array[ARRAYSIZE];
  for (int i = 0; i < ARRAYSIZE; i++)
    scanf("%d", &(array[i]));
  printf("sum = %d\n", sum(array, ARRAYSIZE));
  return 0;
}
