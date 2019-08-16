#include <stdio.h>

main()
{
  int a;
  int b;
  int c;
  int min;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  if (a < b)
    min = a;
  else
    min = b;
  if (c < min)
    min = c;
  printf("%d\n", min);
}
