#include <stdio.h>

main()
{
  int i, n, m[1000];

  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &(m[i]));

  for (i = 0; i < n; i++)
    if (m[i] % 2 != 0)
      printf("%d ", m[i]);
  printf("\n");
  for (i = 0; i < n; i++) 
    if (m[i] % 2 == 0)
      printf("%d ", m[i]);
  printf("\n");
}
