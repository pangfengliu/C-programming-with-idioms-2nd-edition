#include <stdio.h>

int numberBit(int n)
{
  int bit = 0;
  for (int i = 0; i < sizeof(int) * 8; i++) {
    if ((n & 1) != 0)
      bit++;
    n >>= 1;
  }
  return bit;
}

int readNumberComputeOnes(int number[], 
			  int bit[])
{
  int i = 0;
  while (scanf("%d", &(number[i])) != EOF) {
    bit[i] = numberBit(number[i]);
    i++;
  }
  return i;
}

void sortNumber(int number[], int bit[], 
		int count)
{
  for (int i = count - 2; i >= 0; i--)
    for (int j = 0; j <= i; j++)
      if ((bit[j] > bit[j + 1]) || 
	  (bit[j] == bit[j + 1] && 
	   number[j] > number[j + 1])) {
	int temp = number[j];
	number[j] = number[j + 1];
	number[j + 1] = temp;

	temp = bit[j];
	bit[j] = bit[j + 1];
	bit[j + 1] = temp;
      }
}

#define ARRAYSIZE 1000

int main()
{
  int number[ARRAYSIZE];
  int bit[ARRAYSIZE];
  int count =
    readNumberComputeOnes(number, bit);
  sortNumber(number, bit, count);

  for (int i = 0; i < count; i++)
    printf("%d\n", number[i]);
  
  return 0;
}
