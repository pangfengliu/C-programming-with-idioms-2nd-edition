#include <stdio.h>
#include <math.h>

main()
{
  double a, b, c;
  double v, root1, root2;

  scanf("%lf", &a);
  scanf("%lf", &b);
  scanf("%lf", &c);

  v = b * b - 4 * a * c;

  root1 = (-b + sqrt(v))/ (2.0 * a);
  root2 = (-b - sqrt(v))/ (2.0 * a);
  
  if (root1 < root2) {
    printf("%f\n", root1);
    printf("%f\n", root2);
  } else {
    printf("%f\n", root2);
    printf("%f\n", root1);
  }
}
