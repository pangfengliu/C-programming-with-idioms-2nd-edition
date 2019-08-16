#include <stdio.h>
#include <stdlib.h>
#include "ttt.h"

int main(void)
{
  TicTacToe ttt;
  int color = 1;
  int no_winner = 1;
  int i, x, y, pos;

  init(&ttt);

  for (i = 0; i < 9 && no_winner; i++) {
    scanf("%d", &pos);
    x = (pos - 1) / 3;
    y = (pos - 1) % 3;

    if (play(&ttt, color, x, y) != 0) {
      printf("illegal move");
      exit(-1);
    }

    if (win(&ttt, color) == 1) {
      no_winner = 0;
      printf("%d\n", pos);
    }
    color = -color;
  }
  if (no_winner)
    printf("0\n");

  return 0;
}
