#include <stdio.h>

#define MAXM 10000

int getACGT(int *dna[], int i, int j)
{
  int word = dna[i][j / 16];
  int shift = (15 - (j % 16)) * 2;
  return (word & (3 << shift)) >> shift;
}

int setACGT(int *dna[], int i, int j, int v)
{
  int word = dna[i][j / 16];
  int shift = (15 - (j % 16)) * 2;
  word &= ~(3 << shift);
  word |= (v << shift);
  dna[i][j / 16] = word;
} 

void printACGT(int *dna[], int i, int j)
{
  char code[4] = {'A', 'C', 'G', 'T'};
  printf("%c", code[getACGT(dna, i, j)]);
}

void initdna(int *DNA, int *dna[], int m, int n)
{
  int i;
  for (i = 0; i < m; i++)
    dna[i] = &(DNA[i * (n / 16)]);
}

void printDNA(int *DNA, int m, int n)
{
  int *dna[MAXM];
  int i, j;

  initdna(DNA, dna, m, n);

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++)
      printACGT(dna, i, j);
    printf("\n");
  }
}

void up(int *DNA, int m, int n, int column, int step)
{
  int *dna[MAXM];
  int value[MAXM];
  int i, j;

  initdna(DNA, dna, m, n);

  for (i = 0; i < m; i++)
    value[i] = getACGT(dna, i, column);

  step %= m;
  for (i = 0; i < m; i++)
    setACGT(dna, (i + (m - step)) % m, column, value[i]);
}

void down(int *DNA, int m, int n, int column, int step)
{
  int *dna[MAXM];
  int value[MAXM];
  int i, j;

  initdna(DNA, dna, m, n);

  for (i = 0; i < m; i++)
    value[i] = getACGT(dna, i, column);

  step %= m;
  for (i = 0; i < m; i++)
    setACGT(dna, (i + step) % m, column, value[i]);
}


void left(int *DNA, int m, int n, int row, int step)
{
  int *dna[MAXM];
  int value[MAXM];
  int i, j;

  initdna(DNA, dna, m, n);

  for (j = 0; j < n; j++)
    value[j] = getACGT(dna, row, j);

  step %= n;
  for (j = 0; j < n; j++)
    setACGT(dna, row, (j + (n - step)) % n, value[j]);
}

void right(int *DNA, int m, int n, int row, int step)
{
  int *dna[MAXM];
  int value[MAXM];
  int i, j;

  initdna(DNA, dna, m, n);

  for (j = 0; j < n; j++)
    value[j] = getACGT(dna, row, j);

  step %= n;
  for (j = 0; j < n; j++)
    setACGT(dna, row, (j + step) % n, value[j]);
}


void rotate(int *DNA, int m, int n, int row1, int column1, 
	    int row2, int column2, int step)
{
  int *dna[MAXM];
  int value[MAXM];
  int i, j;
  int index = 0;
  int length;

  initdna(DNA, dna, m, n);

  for (i = row1; i < row2; i++)
    value[index++] = getACGT(dna, i, column1);
  for (j = column1; j < column2; j++)
    value[index++] = getACGT(dna, row2, j);

  for (i = row2; i > row1; i--)
    value[index++] = getACGT(dna, i, column2);
  for (j = column2; j > column1; j--)
    value[index++] = getACGT(dna, row1, j);

  length = 2 * (row2 - row1 + column2 - column1);
  step %= length;

  index = (length - step);
  for (i = row1; i < row2; i++) {
    setACGT(dna, i, column1, value[index]);
    index = (index + 1) % length;
  }
  for (j = column1; j < column2; j++) {
    setACGT(dna, row2, j, value[index]);
    index = (index + 1) % length;
  }

  for (i = row2; i > row1; i--) {
    setACGT(dna, i, column2, value[index]);
    index = (index + 1) % length;
  }
  for (j = column2; j > column1; j--) {
    setACGT(dna, row1, j, value[index]);
    index = (index + 1) % length;
  }
}

int main()
{
  int DNA[4] = {27, 27, 0, 27};

  printDNA(DNA, 4, 16);

  up(DNA, 4, 16, 15, 1);
  printDNA(DNA, 4, 16);
#ifdef DEBUG
  down(DNA, 4, 16, 15, 1);
  printDNA(DNA, 4, 16);
#endif

  left(DNA, 4, 16, 1, 8);
  printDNA(DNA, 4, 16);

  rotate(DNA, 4, 16, 0, 6, 3, 14, 2);
  printDNA(DNA, 4, 16);

  return 0;
}
