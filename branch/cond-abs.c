#include <stdio.h>
main()
{
  int i;
  scanf("%d", &i);
  int k = (i > 0)?  i: -i;
  printf("%d\n", k);
}
