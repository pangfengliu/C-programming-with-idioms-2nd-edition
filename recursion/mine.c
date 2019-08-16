#include <stdio.h>

#define FIELDSIZE 9

int inField(int row, int column)
{
  return (row >= 0 && row < FIELDSIZE && column >= 0 && column < FIELDSIZE);
}

int ok(int row, int column, int mineSum[FIELDSIZE][FIELDSIZE], int mineField[FIELDSIZE][FIELDSIZE])
{
  int r, c;
  int sum = 0;
  for (r = -1; r <= 1; r++)
    for (c = -1; c <= 1; c++) 
      if (inField(row + r, column + c))
	sum += mineField[row + r][column + c];
  return (mineSum[row][column] == sum);
} 

void printField(int mineField[FIELDSIZE][FIELDSIZE])
{
  int i, j;
  for (i = 0; i < FIELDSIZE; i++) {
    for (j = 0; j < FIELDSIZE; j++)
      printf("%d ", mineField[i][j]);
    printf("\n");
  }
}

int placeMine(int row, int column, int mineSum[FIELDSIZE][FIELDSIZE], int mineField[FIELDSIZE][FIELDSIZE])
{
  int try;
  int newRow, newColumn;
#ifdef DEBUG
  printf("row %d column %d\n", row, column);
#endif
  if (row == FIELDSIZE) {
    printField(mineField);
    return 1;
  }

  for (try = 0; try <= 1; try++) {
    mineField[row][column] = try;

    newColumn = (column + 1) % FIELDSIZE;
    newRow = row + ((newColumn == 0)? 1 : 0);
#ifdef DEBUG
    printf("newRow %d newColumn %d\n", newRow, newColumn);
#endif
    if (inField(row - 1, column - 1))
      if (!ok(row - 1, column - 1, mineSum, mineField))
	continue;

    if (row == FIELDSIZE - 1)
      if (inField(row, column - 1))
	if (!ok(row, column - 1, mineSum, mineField))
	  continue;

    if (column == FIELDSIZE - 1)
      if (inField(row - 1, column))
	if (!ok(row - 1, column, mineSum, mineField))
	  continue;

    if (placeMine(newRow, newColumn, mineSum, mineField))
      return 1;
  }
  return 0;
}

int main(void)
{
  int i, j;
#ifdef GEN
  int r, c;
#endif
  int mineField[FIELDSIZE][FIELDSIZE];
  int mineSum[FIELDSIZE][FIELDSIZE];

  for (i = 0; i < FIELDSIZE; i++)
    for (j = 0; j < FIELDSIZE; j++)
      scanf("%d", &(mineSum[i][j]));

#ifdef GEN
  for (i = 0; i < FIELDSIZE; i++)
    for (j = 0; j < FIELDSIZE; j++) {
      mineSum[i][j] = 0;
      for (r = -1; r <= 1; r++)
	for (c = -1; c <= 1; c++)
	  if (inField(i + r, j + c))
	    mineSum[i][j] += mineField[i + r][j + c];
    }
  printField(mineSum);
#endif

  if (placeMine(0, 0, mineSum, mineField) == 0)
    printf("no solution\n");
  return 0;
}
