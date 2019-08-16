#include <stdio.h>

main ()
{
  double n, error;
  scanf("%lf%lf", &n, &error);
  double low = 0.0, high = n;
  double x = (low + high) / 2.0;
  while (x * x - n > error || n - x * x > error) {
    if (x * x - n > error)
      high = x;
    else
      low = x;
    x = (low + high) / 2.0;
  }
  printf("x = %9.8f, error = %9.8f\n",
	 x, x * x - n);
}
