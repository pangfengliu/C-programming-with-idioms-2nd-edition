#include <stdio.h>
#include <math.h>

int main()
{
  double r1, r2, theta1, theta2;
  double x1, y1, x2, y2, dx, dy;

  scanf("%lf%lf%lf%lf", &r1, &theta1, &r2, &theta2);
  x1 = r1 * cos(theta1);
  y1 = r1 * sin(theta1);
  x2 = r2 * cos(theta2);
  y2 = r2 * sin(theta2);
  dx = x1 - x2;
  dy = y1 - y2;

  printf("%f\n", sqrt(dx * dx + dy * dy)); 
  return 0;
}
