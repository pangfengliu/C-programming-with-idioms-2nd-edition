#include <stdio.h>
int main(void)
{
  int i = 13;
  printf("%d << 1 = %d\n", i, i << 1);
  printf("%d >> 1 = %d\n", i, i >> 1);
  i = -13;
  printf("%d << 1 = %d\n", i, i << 1);
  printf("%d >> 1 = %d\n", i, i >> 1);
  unsigned int u = 13;
  printf("%u << 1 = %d\n", u, u << 1);
  printf("%u >> 1 = %d\n", u, u >> 1);
  u = 2147483649;
  printf("%u << 1 = %d\n", u, u << 1);
  printf("%u >> 1 = %d\n", u, u >> 1);
  return 0;
}
