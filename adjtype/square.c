#include <stdio.h>

int square(const int i)
{
  return i * i;
}

int main(void)
{
  int x;
  scanf("%d", &x);
  printf("square of %d is %d\n", x, square(x));
  return 0;
}
