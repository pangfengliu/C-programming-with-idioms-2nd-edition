#include <stdio.h>
#define ARRAYSIZE 5
int main(void)
{
  int a[ARRAYSIZE];
  for (int i = 0; i < ARRAYSIZE; i++)
    scanf("%d", &(a[i]));

  int *ptr = a;
  for (int i = 0; i < 2; i++)
    ptr[i] += 3;
  for (int i = 0; i < ARRAYSIZE; i++) 
    printf("a[%d] = %d\n", i, a[i]);
  printf("\n");

  ptr = &(a[2]);
  for (int i = 0; i < 2; i++)
    ptr[i] += 3;
  for (int i = 0; i < ARRAYSIZE; i++) 
    printf("a[%d] = %d\n", i, a[i]);
  return 0;
}
