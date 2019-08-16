#include <stdio.h>
void test(int j)
{
  printf("the address of j = %p\n", &j);
  printf("before adding 1 j = %d\n", j);
  j++;
  printf("after adding 1 j = %d\n", j);
  return;
}
int main(void)
{
  int i;
  scanf("%d", &i);
  printf("the address of i = %p\n", &i);
  printf("before calling test i = %d\n", i);
  test(i);
  printf("after calling test i = %d\n", i);
  test(3 + 7);
  return 0;
}
