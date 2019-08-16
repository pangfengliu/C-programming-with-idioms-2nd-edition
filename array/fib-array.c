#include <stdio.h>
#include <assert.h>
#define FIBARRAYSIZE 100
main()
{
  int n;
  scanf("%d", &n);
  assert(n >= 2 && n < FIBARRAYSIZE);
  
  int fab[FIBARRAYSIZE];
  fab[0] = 0;
  fab[1] = 1;
  for (int i = 2; i < n; i++)
    fab[i] = fab[i - 1] + fab[i - 2];
  for (int i = 0; i < n; i++)
    printf("%d\n", fab[i]);
}
