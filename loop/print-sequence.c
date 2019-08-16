#include <stdio.h>

main()
{
  int i;
  int j;
  int n;
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= i; j++)
      printf("%d\n", j);
}
