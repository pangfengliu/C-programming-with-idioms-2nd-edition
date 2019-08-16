#include <stdio.h>

main()
{
  int a;
  int b;
  int c;
  int d;
  int width, height;
  int pher;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);
  if (c > a)
    width = c - a;
  else
    width = a - c;
  if (d > b)
    height = d - b;
  else
    height = b - d;
  pher = 2 * (width + height);
  printf("%d\n", pher);
}
