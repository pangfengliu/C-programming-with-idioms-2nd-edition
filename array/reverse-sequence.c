#include <stdio.h>

main()
{
  int n;
  int i;
  int numbers[100];

  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &(numbers[i]));

  for (i = n - 1; i >= 0; i--)
    printf("%d ", numbers[i]);
}
