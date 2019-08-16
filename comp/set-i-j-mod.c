#include <stdio.h>
main()
{
  int i, j;
  scanf("%d%d", &i, &j);
  int k = i % j;
  printf("%d\n", k);
  scanf("%d%d", &i, &j);
  k = i % j;
  printf("%d\n", k);
}

