#include <stdio.h>

#define MAXN 100

int sortPointer(int *pointerArray[], int sizeArray[], int *result)
{
  int index = 0;
  int *intPointer;
  int round, temp;
  for (round = 0; sizeArray[round] != 0; round++) {
    for (int i = 0; i < (sizeArray[round]); i++, index++, (pointerArray[round])++)
      result[index] = *(pointerArray[round]);
  }

  for (int i = index - 2; i >= 0; i--)
    for (int j = 0; j <= i; j++)
      if (result[j] > result[j + 1]) {
	temp = result[j];
	result[j] = result[j + 1];
	result[j + 1] = temp;
      }
  return index;
}

int main()
{
  int a[] = {3, 6, 19, -20};
  int b[] = {23, -6, 13};
  int c[] = {-31, 26, 49, 20};
  int *pointerArray[] = {a, b, c};
  int sizeofa = sizeof(a) / sizeof(int);
  int sizeofb = sizeof(b) / sizeof(int);
  int sizeofc = sizeof(c) / sizeof(int);
  int sizeArray[] = {sizeofa, sizeofb, sizeofc, 0};
  int result[MAXN];
  int totalNumber = sortPointer(pointerArray, sizeArray, result);
  
  for (int i = 0; i < totalNumber; i++)
    printf("%d\n", result[i]);

  return 0;
}
