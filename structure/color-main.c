#include <stdio.h>
#include "color.h"

#define N 128

int main(void)
{
  int n;
  int i;
  int r, g, b;
  Color c[N], average;
  
  scanf("%d", &n);
  for  (i = 0; i < n; i++) {
    scanf("%d%d%d", &r, &g, &b);
    initColor(&(c[i]), r, g, b);
    printColor(&c[i]);
  }
  average = averageColor(c, n);
  printColor(&average);
  return 0;
}
