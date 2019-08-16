#include <stdio.h>

void shuffle(int *deck[]);
void print(int *deck[]);

int main(void)
{
  int card[10000];
  int *deck[10000];
  int index = 0;

  while (scanf("%d", &(card[index])) != EOF) {
    deck[index] = &(card[index]);
    index++;
  }
  deck[index] = NULL;

  shuffle(deck);
  print(deck);
  
  return 0;
}
