#include <stdio.h>
void pointerInc(int *p1, int *p2)
{
  printf("The address of p1 is %p\n", &p1);
  printf("The value of p1 is %p\n", p1);
  printf("The address of p2 is %p\n", &p2);
  printf("The value of p2 is %p\n", p2);
  *p1 += 1;
  p1 = p2;
  *p1 += 2;
}
int main(void)
{
  int i, j, *iptr = &i;
  scanf("%d%d", &i, &j);
  printf("The address of i is %p\n", &i);
  printf("The address of j is %p\n", &j);
  printf("The address of iptr is %p\n", &iptr);
  printf("i = %d, j = %d\n", i, j);
  pointerInc(iptr, &j);
  printf("i = %d, j = %d\n", i, j);
  *iptr += 5;
  printf("i = %d, j = %d\n", i, j);
  return 0;
}
