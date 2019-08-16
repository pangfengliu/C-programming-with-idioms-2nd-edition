#include <stdio.h>
#include "polynomial.h"

#define N 33

int main(void)
{
  double coefficient[N];
  double x, y;
  int i, n, m;
  
  scanf("%d", &n);
  for (i = 0; i <= n; i++)
    scanf("%lf", &(coefficient[i]));

  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%lf", &x);
    y = polynomial(x, coefficient, n);
    printf("%f\n", y);
  }
    
  return 0;
}
