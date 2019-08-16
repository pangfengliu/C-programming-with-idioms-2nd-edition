#include <stdio.h>
#include <stdbool.h>

main()
{
  int i, j;
  scanf("%d%d", &i, &j);
  bool k = (i == 3);
  printf("%d\n", k);
  k = (i == j);
  printf("%d\n", k);
}
