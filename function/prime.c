#include <stdio.h>

int prime(int i, int j)
{
  int k;

  while (i % j != 0) {
    k = i % j;
    i = j;
    j = k;
  }
  return(j == 1? 1 : 0);
}

main()
{
  int i, j;
  int count = 0;
  int number[100];
  int prime_count = 0;

  while (scanf("%d", &(number[count])) != EOF)
    count++;

  for (i = 0; i < count - 1; i++)
    for (j = i + 1; j < count; j++)
      if (number[i] < number[j])
	prime_count += prime(number[i], number[j]);
      else if (number[i] > number[j])
	prime_count += prime(number[j], number[i]);
      else
	prime_count++;

  printf("%d\n", prime_count);
}
