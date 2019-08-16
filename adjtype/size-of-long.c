#include <stdio.h>
int main()
{
  long int i;
  printf("%ld\n", sizeof(i));
  scanf("%ld", &i);
  printf("%ld\n", i);
  i++;
  printf("%ld\n", i);
  return 0;
}
