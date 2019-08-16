#include <stdio.h>
#define ROW 3
#define COL 4
main()
{
  int array1[ROW][COL] = {{1, 2}, {4}};
  int array2[ROW][COL] = {{0}};
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++)
      printf("%3d ", array1[i][j]);
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++)
      printf("%3d ", array2[i][j]);
    printf("\n");
  }
}
