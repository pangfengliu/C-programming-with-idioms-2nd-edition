#include <stdio.h>
#include <assert.h>
#define ARRAYSIZE 100
main()
{
  int m;
  scanf("%d", &m);
  assert(m >= 1 && m < ARRAYSIZE);

  int n[ARRAYSIZE];
  for (int i = 0; i < m; i++)
    scanf("%d", &(n[i]));
  for (int i = m - 2; i >= 0; i--)
    for (int j = 0; j <= i; j++)
      if (n[j] > n[j + 1]) {
	int temp = n[j];
	n[j] = n[j + 1];
	n[j + 1] = temp;
      }
  for (int i = 0; i < m; i++)
    printf("%d\n", n[i]);
}
