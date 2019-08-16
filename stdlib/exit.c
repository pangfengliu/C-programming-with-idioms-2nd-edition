#include <stdio.h>
#include <stdlib.h>
void bar(double d)
{
  printf("running bar\n");
  if (d > 0)
    return;
  else
    exit(-1);
}
void foo(double d)
{
  bar(d);
  printf("running foo\n");
  return;
}
int main(void)
{
  double d = 1.0;

  foo(d);
  scanf("%lf", &d);
  foo(d);
}
