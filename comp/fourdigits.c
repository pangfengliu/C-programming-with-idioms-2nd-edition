#include <stdio.h>

main()
{
  int n;
  int sum;
  scanf("%d", &n);
  sum = n / 1000 + (n / 100) % 10 + (n / 10) % 10 + n % 10;
  printf("%d\n", sum);
}
