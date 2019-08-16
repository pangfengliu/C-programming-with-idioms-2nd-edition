#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dice()
{
  return(rand() % 6 + 1); 	/* 1 to 6 */
}

int main(void)
{
  int n;
  int count[13] = {0};	  /* up to 12 */

  scanf("%d", &n);
  srand(time(NULL));
  for (int i = 0; i < n; i++)
    count[dice() + dice()]++;

  for (int i = 2; i <= 12; i++)
    printf("count[%d] = %d proability = %f\n",
	   i, count[i], (double) count[i] / n);

  return 0;
}
