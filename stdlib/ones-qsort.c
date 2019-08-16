#include <stdio.h>
#include <stdlib.h>
#include "ones-qsort.h"

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

void readNumberComputeOnes(NumberSet *numberset)
{
  numberset->count = 0;
  Number *ptr = numberset->numbers;
  while (scanf("%d", &(ptr->value)) != EOF) {
    ptr->bit = numberBit(ptr->value);
    ptr++;
    numberset->count++;
  }
}

int compare(const void *data1,
	    const void *data2)
{
  Number *ptr1 = (Number *)data1;
  Number *ptr2 = (Number *)data2;
  if (ptr1->bit > ptr2->bit)
    return 1;
  else if (ptr1->bit < ptr2->bit)
    return -1;

  if (ptr1->value > ptr2->value)
    return 1;
  else if (ptr1->value < ptr2->value)
    return -1;
  return 0;
}

void sortNumberSet(NumberSet *numberset)
{
  qsort(numberset->numbers, numberset->count,
	sizeof(Number), compare);
}

int main()
{
  NumberSet numberset;
  readNumberComputeOnes(&numberset);
  sortNumberSet(&numberset);

  for (int i = 0; i < numberset.count; i++)
    printf("%d\n", numberset.numbers[i].value);
  return 0;
}
