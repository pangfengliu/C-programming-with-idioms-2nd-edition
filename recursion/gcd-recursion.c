#include <stdio.h>
#include <assert.h>
int gcd(int i, int j)
{
  printf("gcd(%d, %d) = ", i, j);
  int k = i % j;
  if (k == 0)
    return(j);
  return(gcd(j, k));
}
int main(void)
{
  int i, j;
  scanf("%d%d", &i, &j);
  assert(i >= j && j > 0);
  printf("%d\n", gcd(i, j));
  return 0;
}
