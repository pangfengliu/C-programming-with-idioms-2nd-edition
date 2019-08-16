#include <stdio.h>
#include "init-2d.h"

#define N 3
#define M 4

int main(void)
{
  int array[N][M];
  int i, j, k;

  init_2d(array, N, M);

  for (i = 0; i < N; i++)
    for (j = 0; j < M; j++) {
      scanf("%d", &k);
      array[i][j] += k;
    }

  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) 
      printf("%d ", array[i][j]);
    printf("\n");
  }

  return 0;
}
      
