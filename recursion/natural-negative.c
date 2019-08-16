#include <stdio.h>
int natural(int i)
{
  if (i == 1) {
    printf("1 is a natural number\n");
    return 1;
  }
  printf("is %d is a natrual number?\n", i);
  if (natural(i - 1)) {
    printf("OK, %d is a natrual number,", i-1);
    printf(" so %d is a natural number.\n", i);
    return 1;
  }
  return 0;
}
int main(void)
{
  natural(-3);
  return 0;
}
