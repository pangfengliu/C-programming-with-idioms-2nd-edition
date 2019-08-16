#include <stdio.h>

main()
{
  int n;
  int i;
  int power;
  int j;
  scanf("%d", &n);
  scanf("%d", &i);
  power = 1;
  for (j = 0; j < i; j++)
    power *= n;
  printf("%d\n", power);
}
