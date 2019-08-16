#include <stdio.h>

main()
{
  int i;
  int j;
  int n;
  int sum;
  scanf("%d", &i);
  scanf("%d", &j);
  if (i > j)
    n = i - j + 1;
  else
    n = j - i + 1;
  sum = (i + j) * n / 2;
  printf("%d\n", sum);
}
