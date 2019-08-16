#include <stdio.h>
main()
{
  int a[2][3][4];
  int i, j, k;
  int v;

  scanf("%d", &v);
  for (i = 0; i < 2; i++) 
    for (j = 0; j < 3; j++) 
      for (k = 0; k < 4; k++)
	a[i][j][k] = i + j + k + v;

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 4; k++)
	printf("%p ", &(a[i][j][k]));
      printf("\n");
    }
    printf("\n");
  }  

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 4; k++)
	printf("%d ", a[i][j][k]);
      printf("\n");
    }
    printf("\n");
  }
}
