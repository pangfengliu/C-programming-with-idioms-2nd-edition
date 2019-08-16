#include <stdio.h>
#include "wallet.h"

int main()
{
  Wallet wallet;

  init(&wallet);
  show(&wallet);
  receive(&wallet, 20, 0, 2, 10);
  show(&wallet);
  pay(&wallet, 506);
  show(&wallet);
  receive(&wallet, 0, 6, 2, 9);
  purge(&wallet);
  show(&wallet);
}
