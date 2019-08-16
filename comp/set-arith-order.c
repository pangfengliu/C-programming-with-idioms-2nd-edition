#include <stdio.h>
main()
{
  int i, j;
  scanf("%d%d", &i, &j);
  int k = i + 4 * j;
  printf("%d\n", k);
  k = (i + 4) * j;
  printf("%d\n", k);
}
