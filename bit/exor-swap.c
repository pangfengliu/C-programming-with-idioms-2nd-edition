#include <stdio.h>

int main(void)
{
  int i, j;
  scanf("%d%d", &i, &j);
  i ^= j ^= i ^= j;
  printf("%d %d\n", i, j);
  return 0;
}
