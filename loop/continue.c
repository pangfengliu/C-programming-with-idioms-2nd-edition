#include <stdio.h>
main()
{
  int n;
  scanf("%d", &n);

  int sum = 0;
  for (int count = 0; count < n; count++) {
    int i;
    scanf("%d", &i);
    if (i <= 0)
      continue;
    sum += i;
  }
  printf("%d\n", sum);
}
