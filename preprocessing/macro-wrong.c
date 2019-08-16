#include <stdio.h>

#define square(x) x * x

int main(void)
{
  int i, j;
  scanf("%d%d", &i, &j);
  printf("%d\n", square(i + j));
  return 0;
}
