#include <stdio.h>

int max(int array[4][4]);

int main()
{
  int i;
  int j;
  int array[4][4];

  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      scanf("%d", &(array[i][j]));

  printf("%d\n", max(array));
  return 0;
}
