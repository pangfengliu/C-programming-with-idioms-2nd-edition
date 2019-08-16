#include <stdio.h>
main()
{
  int j;
  scanf("%d", &j);
  int i = 0;
  while (i < j) 
    i += 5;
  printf("%d\n", i);
}
