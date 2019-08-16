#include <stdio.h>
#define ARRAYSIZE 10
main()
{
  int a[ARRAYSIZE];

  printf("&a is %p\n", &a);
  printf("a is %p\n", a);
  printf("&(a[0]) is %p\n", &(a[0]));
  printf("a + 3 is %p\n", a + 3);
  printf("&(a[3]) is %p\n", &(a[3]));
}
