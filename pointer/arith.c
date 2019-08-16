#include <stdio.h>
#define ARRAYSIZE 10
int main(void)
{
  int array[ARRAYSIZE];
  int *iptr1 = &(array[3]);
  int *iptr2 = iptr1 + 4;
  printf("iptr1 = %p\n", iptr1);
  printf("iptr2 = %p\n", iptr2);
  printf("iptr2 - iptr1 = %ld\n", iptr2-iptr1);
  return 0;
}
