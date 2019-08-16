#include<stdio.h>

int main(void)
{
  signed char sc;
  unsigned char uc;
  for (uc = 0; uc < 200; uc++)
    printf("uc = %d\n", uc);
  for (sc = 0; sc < 200; sc++)
    printf("sc = %d\n", sc);
  return 0;
}
