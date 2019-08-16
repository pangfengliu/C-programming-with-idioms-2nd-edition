#include <stdio.h>

int square(const int i)
{
  i++;
  return (i * i);
}

int main(void)
{
  int x = 10;
  printf("square of %d is %d\n", x, square(x));
  return 0;
}
