#include <stdio.h>
#include <stdlib.h>
#ifdef NDEBUG
#define assert(cond) 0
#else
#define assert(cond) \
if (!(cond)) {\
  printf("Assertion failed: %s, " \
  "file %s, line %d\n",	\
  #cond, __FILE__, __LINE__); \
  exit(0);\
}
#endif
int main(void)
{
  int i = 0;
  assert(i == 1);
  return 0;
}
