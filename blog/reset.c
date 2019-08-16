#include <stdio.h>

int main()
{
  char i = 1;
  char j;

  scanf("%d", &j);
  if (i & j)
    printf("yes.\n");
  else
    printf("no.\n");
  
  return 0;
}
