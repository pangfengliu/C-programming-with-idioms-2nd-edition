#include <stdio.h>
#include <assert.h>
#define ARRAYSIZE 1000
main()
{
  int n, column;
  scanf("%d%d", &n, &column);
  assert(n < ARRAYSIZE && column > 0);
  int composite[ARRAYSIZE];
  for (int i = 2; i <= n; i++)
    composite[i] = 0;
  int j = 2;
  while (j * j <= n) {
    while (composite[j] == 1)
      j++;
    for (int i = 2 * j; i <= n; i += j)
      composite[i] = 1;
    j++;
  }
  int count = 0;
  for (int i = 2; i <= n; i++)
    if (composite[i] == 0) {
      if (count % column == (column - 1))
	printf("%3d\n", i);
      else
	printf("%3d ", i);
      count++;
    }
}
