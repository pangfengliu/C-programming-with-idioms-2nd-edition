double polynomial(double x, double coefficient[], int n)
{
  double x_power;
  double y = 0.0;
  int i, j;

  for (i = 0; i <= n; i++) {
    x_power = 1.0;
    for (j = 0; j < i; j++)
      x_power *= x;
    y += coefficient[i] * x_power;
  }
  return y;
}
