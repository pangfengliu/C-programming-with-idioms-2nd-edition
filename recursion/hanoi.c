#include <stdio.h>
#include <assert.h>
void hanoi(int n, char src, char dst,
	   char buffer)
{
  printf("hanoi(%d, %c, %c, %c)\n", n, 
	 src, dst, buffer);
  if (n == 1)
    printf("from %c to %c\n", src, dst);
  else {
     hanoi(n - 1, src, buffer, dst);
     printf("from %c to %c\n", src, dst);
     hanoi(n - 1, buffer, dst, src);
  }
}
int main(void)
{
  int n;
  scanf("%d", &n);
  assert(n > 1);
  hanoi(n, 'A', 'C', 'B');
  return 0;
}
