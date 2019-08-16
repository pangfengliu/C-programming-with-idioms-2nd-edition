#include <stdio.h>
main()
{
  float x;
  scanf("%f", &x);

  float e = 1.0;
  int n = 10;
  int factorial = 1;
  float xpower = 1.0;

  for (int i = 1; i <= n; i++) {
    factorial *= i;
    xpower *= x;
    e += xpower / factorial;
  }

  printf("%f\n", e);
}
