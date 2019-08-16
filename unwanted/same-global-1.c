#include <stdio.h>

int i;

int main(int argc, char *argv[])
{
  foo();
  i++;
  printf("main: i = %d\n", i);
  return 0;
}
