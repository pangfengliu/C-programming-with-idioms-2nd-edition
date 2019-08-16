#include <stdio.h>

main()
{
  int n;
  int i;
  int numbers[1000];

  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &(numbers[i]));

  for (i = 0; i < n; i += 2) 
    printf("%d ", numbers[i]);
  printf("\n");

  for (i = 1; i < n; i += 2)
    printf("%d ", numbers[i]);
  printf("\n");
}
