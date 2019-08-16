#include <stdio.h>
#include <stdbool.h>
main()
{
  int n;
  scanf("%d", &n);
  bool prime = true;
  for (int i = 2; ((i * i) <= n) && prime; i++)
    if ((n % i) == 0)
      prime = false;
  printf("%d\n", prime);
}
