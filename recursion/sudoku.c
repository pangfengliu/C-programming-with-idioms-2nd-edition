#include <stdio.h>
#include <stdbool.h>
/* placenumber */
#define SUBBLOCK 3
#define BLOCK 9
#define CELLS (BLOCK * BLOCK)

bool placeNumber(int n,
		 int sudoku[BLOCK][BLOCK])
{
  if (n == CELLS) {
    for (int i = 0; i < BLOCK; i++) {
      for (int j = 0; j < BLOCK; j++)
	printf("%d ", sudoku[i][j]);
      printf("\n");
    }
    return true;
  }
  /* test */
  int row = n / BLOCK;
  int col = n % BLOCK;
  if (sudoku[row][col] != 0)
    return(placeNumber(n + 1, sudoku));
  for (int try = 1; try <= BLOCK; try++) {
    bool conflict = false;
    for (int i = 0; i < BLOCK && !conflict; i++)
      if (((col != i) && (sudoku[row][i]==try))
	  ||
	  ((row != i) && (sudoku[i][col]==try)))
	conflict = true;
    if (!conflict) {
      int blockRow = row / SUBBLOCK;
      int blockCol = col / SUBBLOCK;
      for (int i = 0; i < SUBBLOCK && !conflict;
	   i++)
	for (int j = 0;
	     j < SUBBLOCK && !conflict;
	     j++)
	  if (sudoku[SUBBLOCK * blockRow + i]
	      [SUBBLOCK * blockCol + j] 
	      == try)
	    conflict = true;
      if (!conflict) {
	sudoku[row][col] = try;
	if (placeNumber(n + 1, sudoku))
	  return true;
      }
    }
  }
  sudoku[row][col] = 0;
  return false;
}
/* main */
int main(void)
{
  int sudoku[BLOCK][BLOCK];
  for (int i = 0; i < BLOCK; i++)
    for (int j = 0; j < BLOCK; j++)
      scanf("%d", &(sudoku[i][j]));
  placeNumber(0, sudoku);
  return 0;
}
/* end */
