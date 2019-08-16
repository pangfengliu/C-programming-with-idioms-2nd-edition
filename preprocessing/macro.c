#include <stdio.h>

#define square(x) x * x

int main(void)
{
  int i;
  scanf("%d", &i);
  printf("%d\n", square(i));
  return 0;
}
