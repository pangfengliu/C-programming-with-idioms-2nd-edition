#include <stdio.h>

int square(int x)
{
  return x * x;
}

int main(void)
{
  int i, j;
  scanf("%d%d", &i, &j);
  printf("%d\n", square(i + j));
}
