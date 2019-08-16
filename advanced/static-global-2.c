#include <stdio.h>

static int i;

void foo(void)
{
  i++;
  printf("foo: i = %d\n", i);
}

void bar(void)
{
  i++;
  printf("bar: i = %d\n", i);
}
