#include <stdio.h>
int main(void)
{
  int i;
  float f;
  double df;
  scanf("%d%f%lf", &i, &f, &df);
  printf("int%d address%p float%f double%f\n", 
	 i, &i, f, df);
  return 0;
}
