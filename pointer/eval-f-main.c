#include <stdio.h>
#include "eval-f.h"

#define N 256

int main(void)
{
  int n = 0;
  int x, y;
  int xy[2 * N];
  int xy_n = 0;
  int max, max_index;
  int *iptr[N];

  while (scanf("%d%d", &x, &y) != EOF) {
    iptr[n] = &(xy[xy_n]);
    n++;
    xy[xy_n] = x;
    xy_n++;
    xy[xy_n] = y;
    xy_n++;
  }

  max = eval_f(iptr, n, &max_index);
  printf("%d %d\n", max, max_index);

  return 0;
}
