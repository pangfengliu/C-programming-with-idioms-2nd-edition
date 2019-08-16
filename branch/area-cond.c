#include <stdio.h>

main()
{
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);

  int width = (c > a)? c - a : a - c;
  int height = (d > b)? d - b : b - d;

  int area = width * height;
  int perriphral = 2 * (width + height);

  printf("%d\n", area);
  printf("%d\n", perriphral);
}

