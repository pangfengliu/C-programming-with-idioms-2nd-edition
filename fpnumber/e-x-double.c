#include <stdio.h>
main()
{
  double x;
  scanf("%lf", &x);

  double e = 1.0;
  int n = 10;
  int factorial = 1;
  double xpower = 1.0;

  for (int i = 1; i <= n; i++) {
    factorial *= i;
    xpower *= x;
    e += xpower / factorial;
  }

  printf("%f\n", e);
}
