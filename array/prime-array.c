#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define ARRAYSIZE 101
main()
{
  int n;
  scanf("%d", &n);
  assert(n >= 2 && n < ARRAYSIZE);
  
  bool prime[ARRAYSIZE];
  for (int i = 2; i <= n; i++)
    prime[i] = true;
  int j = 2;
  while (j * j <= n) {
    while (!prime[j])
      j++;
    for (int i = 2 * j; i <= n; i += j)
      prime[i] = false;
    j++;
  }
  for (int i = 2; i <= n; i++)
    if (prime[i])
      printf("%d\n", i);
}
