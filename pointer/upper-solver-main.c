#include <stdio.h>
#define N 256

void upper_solver(double *A, double *x, double *y, 
		  int n);
int main(void)
{
  int n;
  double A[N * (N + 1) / 2];
  double *aptr = A;
  double x[N];
  double y[N];

  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) {
      scanf("%lf", aptr);
      aptr++;
    }

  for (int i = 0; i < n; i++)
    scanf("%lf", &(y[i]));

  upper_solver(A, x, y, n);

  for (int i = 0; i < n; i++)
    printf("%f", x[i]);

  return 0;
}
