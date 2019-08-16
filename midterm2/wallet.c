#include <stdio.h>
#include "wallet.h"

void init(Wallet *wallet)
{
  int i;
  wallet->value[0] = 50;
  wallet->value[1] = 10;
  wallet->value[2] = 5;
  wallet->value[3] = 1;

  for (i = 0; i < DENOMINATION; i++)
    wallet->coin[i] = 0;
}

int min(int a, int b)
{
  return (a < b? a : b);
}

void pay(Wallet *wallet, int amount)
{
  int i;
  for (i = 0; i < DENOMINATION; i++) {
    int numCoins = min(wallet->coin[i], amount / wallet->value[i]);
    wallet->coin[i] -= numCoins;
    amount -= wallet->value[i] * numCoins;
  }
}

void receive(Wallet *wallet, int fifty, int ten, int five, int one)
{
  wallet->coin[0] += fifty;
  wallet->coin[1] += ten;
  wallet->coin[2] += five;
  wallet->coin[3] += one;
}

void purge(Wallet *wallet)
{
  int total = 0;
  int i;
  for (i = 0; i < DENOMINATION; i++)
    total += wallet->coin[i] * wallet->value[i];

  for (i = 0; i < DENOMINATION; i++) {
    wallet->coin[i] = total / wallet->value[i];
    total %= wallet->value[i];
  }
}

void show(Wallet *wallet)
{
  int i;
  for (i = 0; i < DENOMINATION; i++)
    printf("%d coin %d\n", wallet->value[i], wallet->coin[i]);
}

