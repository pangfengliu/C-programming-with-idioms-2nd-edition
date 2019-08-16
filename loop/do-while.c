#include <stdio.h>
main()
{
  int i;
  scanf("%d", &i);
  do
    i++;
  while (i < 0);
  printf("%d\n", i);
}
