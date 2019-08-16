#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
  srand(time(NULL));
  
  int n;
  scanf("%d", &n);

  int count = 0;
  for (int i = 0; i < n; i++) {
    double x = (double) rand() / RAND_MAX;
    double y = (double) rand() / RAND_MAX;
    if (x * x + y * y <= 1.0)
      count++;
  }
  printf("pi is about %f\n", 
	 ((double) count) / n * 4.0);
  return 0;
}
