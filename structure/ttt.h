struct tictactoe {
  int board[3][3];
};
typedef struct tictactoe TicTacToe;
void init(TicTacToe *ttt); 
int play(TicTacToe *ttt, int color, int x, int y);
int win(TicTacToe *ttt, int color);
