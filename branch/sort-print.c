#include <stdio.h>
main()
{
  int i, j;
  scanf("%d%d", &i, &j);
  if (i > j) {
    printf("%d\n", j);
    printf("%d\n", i);
  } else {    
    printf("%d\n", i);
    printf("%d\n", j);
  }
}

