/* compare */
#include <stdio.h>
#include <stdlib.h>

int compare(const void *data1,
	    const void *data2)
{
  int *ptr1 = (int *)data1;
  int *ptr2 = (int *)data2;
  if (*ptr1 < *ptr2)
    return -1;
  else if (*ptr1 > *ptr2)
    return 1;
  else
    return 0;
}
/* main */
#define ARRAYSIZE 10
int main(void)
{
  int array[ARRAYSIZE];
  for (int i = 0; i < ARRAYSIZE; i++)
    scanf("%d", &(array[i]));
  qsort(array, ARRAYSIZE, sizeof(int), compare);
  for (int i = 0; i < ARRAYSIZE; i++)
    printf("%d ", array[i]);
  printf("\n");
  int key;
  scanf("%d", &key);
  int low = 0, high = ARRAYSIZE - 1;
  while (low <= high) {
    int middle = (low + high) / 2;
    if (array[middle] == key) {
      printf("array[%d] == %d\n", middle, key);
      return 0;
    } else if (array[middle] < key) 
      low = middle + 1;
    else
      high = middle - 1;
  }
  printf("key %d not found\n", key);
  return 0;
}
/* end */
