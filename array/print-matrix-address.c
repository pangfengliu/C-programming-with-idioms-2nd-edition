#include <stdio.h>
#define X 2
#define Y 3
#define Z 4
main()
{
  int a[2][3][4];
  for (int i = 0; i < X; i++) {
    for (int j = 0; j < Y; j++) {
      for (int k = 0; k < Z; k++) 
	printf("%p ", &(a[i][j][k]));
      printf("\n");
    }
    printf("\n");
  }
}
