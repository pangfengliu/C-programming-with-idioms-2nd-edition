#include <stdio.h>
#define ARRAYSIZE 5
main()
{
  int A[ARRAYSIZE], B[ARRAYSIZE];
  for (int i = 0; i < ARRAYSIZE; i++)
    scanf("%d", &(A[i]));
  for (int i = 0; i < ARRAYSIZE; i++)
    scanf("%d", &(B[i]));
  int C = 0;
  for (int i = 0; i < ARRAYSIZE; i++)
    C += A[i] * B[i];
  printf("%d\n", C);
}
