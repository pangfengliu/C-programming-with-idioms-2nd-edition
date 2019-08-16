#include <stdio.h>

main()
{
  int n;
  int i;
  scanf("%d", &n);
  i = ((n % 3 == 0) && (n % 5 != 0)) || 
    ((n % 3 == 0) && (n % 5 != 1));
  printf("%d\n", i);
}
