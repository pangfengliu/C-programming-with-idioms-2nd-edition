#include <stdio.h>
#define X 2
#define Y 3
#define Z 4
main()
{
  int a[X][Y][Z];

  for (int i = 0; i < X; i++)
    printf("%p\n", &(a[i][1]));
  printf("\n");
  for (int i = 0; i < X; i++)
    printf("%p\n", a[i][1]);
  printf("\n");
  for (int i = 0; i < X; i++)
    printf("%p\n", &(a[i]));
  printf("\n");
  for (int i = 0; i < X; i++)
    printf("%p\n", a[i]);
  printf("\n");
  printf("%p\n", &a);
  printf("%p\n", a);
}
