#include <stdio.h>
#define X 2
#define Y 3
#define Z 4
main()
{
  int a[X][Y][Z];
  printf("size of a[0][0][0] = %ld\n",
	 sizeof(a[0][0][0]));
  printf("size of a[0][0] = %ld\n",
	 sizeof(a[0][0]));
  printf("size of a[0] = %ld\n", sizeof(a[0]));
  printf("size of a = %ld\n", sizeof(a));
}
