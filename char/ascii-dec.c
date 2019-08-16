#include <stdio.h>
#include <ctype.h>
int main(void)
{
  printf("   0123456789\n");
  for (int c = 30; c <= 127; c++) {
    if (c % 10 == 0)
      printf("%2d ", c / 10);
    if (isprint(c))
      printf("%c", c);
    else
      printf(" ");
    if (c % 10 == 9)
      printf("\n");
  }
  return 0;
}

