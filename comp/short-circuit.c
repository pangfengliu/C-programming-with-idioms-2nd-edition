#include <stdio.h>
main()
{
  int i, j;
  scanf("%d%d", &i, &j);

  int k = 3, l = 4;
  printf("%d\n", ((k = i) > 0 || (l = j) > 0));
  printf("%d\n", k);
  printf("%d\n", l);
}
