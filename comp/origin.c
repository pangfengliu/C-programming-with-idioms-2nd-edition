#include <stdio.h>

main()
{
  int a;
  int b;
  int c;
  int d;
  int i;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);
  i = (a * d == b * c);
  printf("%d\n", i);
}
