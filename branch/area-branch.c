#include <stdio.h>
main()
{
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  int width, height;
  if (c > a)
    width = c - a;
  else
    width = a - c;
  if (d > b)
    height = d - b;
  else
    height = b - d;
  int area = width * height;
  int perriphral = 2 * (width + height);
  printf("%d\n", area);
  printf("%d\n", perriphral);
}

