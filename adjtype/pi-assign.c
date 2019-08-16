#include <stdio.h>

int main(void)
{
  const double pi = 3.1415926;
  double radius = 2.0;
  pi = 3.0;
  printf("area = %f\n", pi * radius * radius);
  return 0;
}
