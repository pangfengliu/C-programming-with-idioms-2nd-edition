#include <stdio.h>
#include <stdbool.h>
main()
{
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  bool identialRoot =
    (b * b - 4 * a * c == 0);
  printf("%d\n", identialRoot);
}
