#include <stdio.h>
int main()
{
  int i, j;
  scanf("%d%d", &i, &j);
  int temp = i;
  i = j;
  j = temp;
  printf("%d\n%d\n", i, j);
  return 0;
}
