#include <stdio.h>
#define X 2
#define Y 3
#define Z 4
int main()
{
  int a[X][Y][Z];

  printf("a[0][0] + 1 = %p\n", a[0][0] + 1);
  printf("&(a[0][0][0]) + 1 = %p\n",
	 &(a[0][0][0]) + 1);
  printf("&(a[0][0][1]) = %p\n\n",
	 &(a[0][0][1]));

  printf("a[0] + 1 = %p\n", a[0] + 1);
  printf("a[0][1] = %p\n", a[0][1]);
  printf("a[0][0] + 4 = %p\n", a[0][0] + 4);
  printf("&(a[0][0][0]) + 4 = %p\n",
	 &(a[0][0][0]) + 4);
  printf("&(a[0][1][0]) = %p\n\n",
	 &(a[0][1][0]));

  printf("a + 1 = %p\n", a + 1);
  printf("a[1] = %p\n", a[1]);
  printf("a[0] + 3 = %p\n", a[0] + 3);
  printf("a[0][0] + 12 = %p\n", a[0][0] + 12);
  printf("&(a[0][0][0]) + 12 = %p\n",
	 &(a[0][0][0]) + 12);
  printf("&(a[1][0][0]) = %p\n",
	 &(a[1][0][0]));
  
  return 0;
}
