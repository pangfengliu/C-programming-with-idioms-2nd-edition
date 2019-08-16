#include <stdio.h>

main()
{
  int a;
  int b;
  int c;
  int v;
  int i;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  v = b * b - 4 * a * c;
  if (v == 0)
    i = 0;
  else if (v > 0)
    i = 1;
  else
    i = -1;
  printf("%d\n", i);
}
