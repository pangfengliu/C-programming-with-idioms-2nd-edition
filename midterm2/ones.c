/* constrint: n is a singed integer (int) */

#include <stdio.h>

int ones(int n)
{
  int i;
  int maxLength = 0;
  int currentLength = 0;
  for (i = 0; i < 32; i++, n >>= 1) 
    if (n & 1) 
      currentLength++;
    else {
      if (currentLength > maxLength)
	maxLength = currentLength;
      currentLength = 0;
    }
  return maxLength;
}

int main()
{
  unsigned int n;
  while (scanf("%d", &n) != EOF)
    printf("%d\n", ones(n));
  return 0;
}
