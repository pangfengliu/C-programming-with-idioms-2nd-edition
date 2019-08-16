#include <stdio.h>
main()
{
  int i, j;
  scanf("%d%d", &i, &j);

  int k = 3, l = 4;
  k = i;
  l = j;
  if (k > 0 || l > 0) {
    printf("%d\n", k);
    printf("%d\n", l);
  }
}
