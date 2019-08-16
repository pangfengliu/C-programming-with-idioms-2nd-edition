#include <stdio.h>

#define DENOMINATION 4

typedef struct wallet 
{
  int value[DENOMINATION];
  int coin[DENOMINATION];
} Wallet;
  
void init(Wallet *wallet);
void pay(Wallet *wallet, int amount);
void receive(Wallet *wallet, int fifty, int ten, int five, int one);
void purge(Wallet *wallet);
void show(Wallet *wallet);

