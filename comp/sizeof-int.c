#include <stdio.h>
main()
{
  int i;
  printf("%ld\n", sizeof(i));
  scanf("%d", &i);
  printf("%d\n", i);
  i++;
  printf("%d\n", i);
}
