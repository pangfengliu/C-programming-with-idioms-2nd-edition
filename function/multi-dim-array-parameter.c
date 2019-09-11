#include <stdio.h>
void printMatrix(int a[4][3], int i, int j)
{
  printf("a[%d][%d] = %d\n", i, j, a[i][j]);
}
int main(void)
{
  int array[3][4];
  for (int i = 0; i < 3; i++)			
    for (int j = 0; j < 4; j++)
      scanf("%d", &(array[i][j]));
  printf("array[2][1] = %d\n", array[2][1]);
  printMatrix(array, 2, 1);
  printf("array[0][2] = %d\n", array[0][2]);
  printMatrix(array, 0, 2);
  return 0;
}
