#include <stdio.h>
#include <assert.h>

void printNumbers(int start, int end)
{
  for (int i = start; i <= end; i++)
    printf("%d\n", i);
  return;
}
int main(void)
{
  int a, b;
  scanf("%d%d", &a, &b);
  assert(a <= b);
  printNumbers(a, b);
  return 0;
}
