#include <stdio.h>
void printArray(int array[], int n)
{
  printf("array is at %p\n", array);
  for (int i = 0; i < n; i++)
    printf("array[%d] = %d\n", i, array[i]);
  return;
} 
#define ASIZE 3
#define BSIZE 5
int main(void)
{
  int a[ASIZE];
  int b[BSIZE];
  printf("main: a = %p\n", a);
  printf("main: b = %p\n", b);
  for (int i = 0; i < ASIZE; i++)
    scanf("%d", &(a[i]));
  for (int i = 0; i < BSIZE; i++)
    scanf("%d", &(b[i]));
  printArray(a, ASIZE);
  printArray(b, BSIZE);
  return 0;
}
