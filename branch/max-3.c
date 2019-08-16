#include <stdio.h>
main()
{
  int i, j, k, max;
  scanf("%d%d%d", &i, &j, &k);
  if (i > j)
    max = i;
  else
    max = j;
  if (k > max)
    max = k;
  printf("%d\n", max);
}
