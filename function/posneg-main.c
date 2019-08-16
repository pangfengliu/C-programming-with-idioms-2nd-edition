#include <stdio.h>

void posneg(int array[4][4], int results[2]);

int main()
{
  int i;
  int j;
  int array[4][4];
  int results[2];

  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      scanf("%d", &(array[i][j]));

  posneg(array, results);
  printf("%d\n", results[0]);
  printf("%d\n", results[1]);
  return 0;
}
