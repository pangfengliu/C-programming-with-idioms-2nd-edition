#include "ttt.h"

void init(TicTacToe *ttt)
{
  int i, j;
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
      ttt->board[i][j] = 0;
  return;
}

int play(TicTacToe *ttt, int color, int x, int y)
{
  if (ttt->board[x][y] != 0) 
    return -1;
  else {
    ttt->board[x][y] = color;
    return 0;
  }
}

int win(TicTacToe *ttt, int color)
{
  int i, j;
  int count;

  for (i = 0; i < 3; i++) {
    count = 0;
    for (j = 0; j < 3; j++) 
      if (ttt->board[i][j] == color)
	count++;
    if (count == 3)
      return 1;
  }

  for (j = 0; j < 3; j++) {
    count = 0;
    for (i = 0; i < 3; i++) 
      if (ttt->board[i][j] == color)
	count++;
    if (count == 3)
      return 1;
  }

  if (ttt->board[0][0] == color && ttt->board[1][1] == color 
      && ttt->board[2][2] == color)
    return 1;

  if (ttt->board[0][2] == color && ttt->board[1][1] == color 
      && ttt->board[2][0] == color)
    return 1;
  
  return 0;
}
