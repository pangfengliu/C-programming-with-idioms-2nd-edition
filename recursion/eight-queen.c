#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>		/* for abs */
#define QUEENS 8
void placeQueen(int i, int queenPos[QUEENS])
{
  if (i == QUEENS) {
    for (int k = 0; k < QUEENS; k++)
      printf("%d ", queenPos[k]);
    printf("\n");
    return;
  }
  for (int k = 0; k < QUEENS; k++) {
    bool conflict = false;
    for (int j = 0; j < i && !conflict; j++)
      if (queenPos[j] == k || 
	  abs(k - queenPos[j]) == (i - j))
	conflict = true;
    if (!conflict) {
      queenPos[i] = k;
      placeQueen(i + 1, queenPos);
    }
  }
}
int main(void)
{
  int queenPos[QUEENS];
  placeQueen(0, queenPos);
  return 0;
}
