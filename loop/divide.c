#include <stdio.h>

int main()
{
  int k;
  scanf("%d", &k);

  int count = 0, prev = 0;
  int toPrint;
  int digit;
  while (scanf("%d", &digit) != EOF) {
    int value = 10 * prev + digit;
    toPrint = value / k;
    if (!(count == 0 && toPrint == 0))
      printf("%d\n", toPrint);
    prev = value % k;
    count++;
  }
  if (count == 1 && toPrint == 0)
    printf("0\n");
}
