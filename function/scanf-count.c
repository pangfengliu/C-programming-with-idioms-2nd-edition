#include <stdio.h>

int main()
{
  int sum = 0, count = 0, i;
  while (scanf("%d", &i) != EOF) {
    sum += i;
    count++;
  }
  printf("%d\n", sum / count);
  return 0;
}
