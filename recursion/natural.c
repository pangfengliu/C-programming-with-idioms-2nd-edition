#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
bool natural(int i)
{
  if (i == 1) {
    printf("1 is a natural number.\n");
    return true;
  }
  printf("Is %d a natural number?\n", i);
  if (natural(i - 1)) {
    printf("%d is a natural number,", i - 1);
    printf(" so %d is a natural number.\n", i);
    return true;
  }
  return false;
}
int main(void)
{
  int n;
  scanf("%d", &n);
  assert(n > 0);
  printf("%d\n", natural(3));
  return 0;
}
