#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 0;
 start:  if (i >= 10) 
    goto next;
  printf("i = %d\n", i);
  i++;
  goto start;
 next: return 0;
}
