#include <stdio.h>
#include <stdbool.h>
main()
{
  int i = 3;
  int j = 0;
  bool k = (i && j);
  printf("%d\n", k);
  k = (i || j);
  printf("%d\n", k);
  k = !i;
  printf("%d\n", k);
}
