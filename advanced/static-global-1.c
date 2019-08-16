#include <stdio.h>

void foo(void);
void bar(void);

static int i;

int main(int argc, char *argv[])
{
  foo();
  bar();
  i++;
  printf("main: i = %d\n", i);
  return 0;
}
