#include <stdio.h>
#include <stdbool.h>

main()
{
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);

  bool valid =
    (a > 0 && b > 0 && c > 0 &&
     a + b > c && b + c > a && a + c > b);
  printf("%d\n", valid);
}
