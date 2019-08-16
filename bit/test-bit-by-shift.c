#include <stdio.h>
int main(void)
{
  char test = (1 << 3);
  char value = 49;
  if (value & test)
    printf("yes.\n");
  else
    printf("no.\n");
  value |= test;
  if (value & test)
    printf("yes.\n");
  else
    printf("no.\n");
  value &= ~test;
  if (value & test)
    printf("yes.\n");
  else
    printf("no.\n");
  return 0;
}
