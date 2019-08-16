#include <stdio.h>
#include <stdlib.h>

#define assert(cond) \
if (!(cond)) {\
  printf("Assertion failed: %s", #cond);\
  exit(0);\
}
int main(void)
{
  int i = 0;
  assert(i == 1);
  return 0;
}
