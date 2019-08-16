#include <stdio.h>

main()
{
  int i;
  int n;
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    printf("%d\n", i);
  for (i = n - 1; i >= 1; i--)
    printf("%d\n", i);
}
