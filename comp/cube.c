#include <stdio.h>

main()
{
  int a, b, c, d, e;
  int area;
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
  
  area = 2 * (a * b + b * c + c * a) + 
    8 * d * ((a - 2 * e) + (b - 2 * e) + (c - 2 * e));
  printf("%d\n", area);
}
