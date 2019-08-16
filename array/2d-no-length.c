#include <stdio.h>
main()
{
  int array[][3] = {{1, 2, 3}, {4, 5, 6}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++)
      printf("%3d ", array[i][j]);
    printf("\n");
  }
}
