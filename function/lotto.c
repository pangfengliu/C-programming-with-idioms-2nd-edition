#include <stdio.h>

int getSpecialPrize(int lottoNumber, int specialPrize[])
{
  int i;
  for (i = 0; i < 3; i++)
    if (lottoNumber == specialPrize[i])
      return 1;
  return 0;
}

int getSameDigit(int n, int m)
{
  int mod = 100000000;
  int i;
  for (i = 8; i >= 3; i--, mod /= 10) {
    if (n % mod == m % mod)
      return i;
  }
  return 0;			/* does not matter */
}

int getFirstPrize(int lotto, int firstPrize[]) 
{
  int firstPrizeMoney[] = {0, 0, 0, 200, 1000, 4000, 10000, 40000, 200000};
  int maxSameDigit = 0;
  int sameDigit;
  int i;
  for (i = 0; i < 3; i++) {
    sameDigit = getSameDigit(lotto, firstPrize[i]);
    if (sameDigit > maxSameDigit)
      maxSameDigit = sameDigit;
  }
  return firstPrizeMoney[maxSameDigit];
}

int main()
{
  int specialPrize[3];
  int firstPrize[3];
  int lottoNumber;
  int prize = 0;
  int i;

  for (i = 0; i < 3; i++)
    scanf("%d", &(specialPrize[i]));
  for (i = 0; i < 3; i++)
    scanf("%d", &(firstPrize[i]));

  while (scanf("%d", &lottoNumber) != EOF) {
    if (getSpecialPrize(lottoNumber, specialPrize))
      prize += 2000000;
    else
      prize += getFirstPrize(lottoNumber, firstPrize);
  }
  printf("%d\n", prize);
}
