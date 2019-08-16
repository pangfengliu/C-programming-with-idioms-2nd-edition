#include <stdio.h>
#include <stdint.h>
int main()
{
  uint32_t i;
  printf("%ld\n", sizeof(i));
  scanf("%u", &i);
  printf("%u\n", i);
  i++;
  printf("%u\n", i);
  return 0;
}
