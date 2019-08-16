#include <stdio.h>
void foo(void)
{
  int i = 0;
  i++;
  printf("foo: i = %d\n", i);
}
void bar(void)
{
  static int i = 0; 
  i++;
  printf("bar: i = %d\n", i);
}
int main()
{
  for (int j = 0; j < 5; j++)
    foo();
  for (int j = 0; j < 5; j++)
    bar();
  return 0;
}
