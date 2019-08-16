#include <stdio.h>
int main(void)
{
  int i;
  float f;
  double df;
  scanf("%d%f%lf", &i, &f, &df);
  printf("%d %p %f %f\n", i, &i, f, df);
  return 0;
}
