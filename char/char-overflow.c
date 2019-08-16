#include <stdio.h>
int main(void)
{
  int i;
  scanf("%d", &i);
  char c = i;
  c++;
  i++;
  printf("c = %d\n", c);
  printf("i = %d\n", i);
  return 0;
}
