#include <stdio.h>
#define ARRAYSIZE 5
int main(void)
{
  int a[ARRAYSIZE];
  for (int i = 0; i < ARRAYSIZE; i++)
    scanf("%d", &(a[i]));

  int *ptr = a;
  for (int i = 0; i < ARRAYSIZE; i++, ptr++) {
    printf("%p\n", ptr);
    *ptr += 3;
  }
  for (int i = 0; i < ARRAYSIZE; i++) 
    printf("a[%d] = %d\n", i, a[i]);
  return 0;
}
