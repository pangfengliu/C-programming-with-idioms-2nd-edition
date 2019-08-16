#include <stdio.h>
main()
{
  double x;
  scanf("%lf", &x);

  double e = 1.0;
  int n = 20;
  double term = 1.0;

  for (int i = 1; i <= n; i++) {
    term *= (x / i);
    e += term;
  }

  printf("%f\n", e);
}
