#include <stdio.h>
#define ARRAYSIZE 10

main()
{
  int a[ARRAYSIZE];
  for (int i = 0; i < ARRAYSIZE; i++)
    scanf("%d", &(a[i]));
  for (int i = 0; i < ARRAYSIZE; i++)
    printf("%d\n", a[i]);
}
