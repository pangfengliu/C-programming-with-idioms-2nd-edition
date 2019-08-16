#include<stdio.h>
int main(void)
{
  int integer;
  long int longInteger;
  short int shortInteger;
  long long int longLongInteger;
  scanf("%d", &integer);
  scanf("%ld", &longInteger);
  scanf("%hd", &shortInteger);
  scanf("%lld", &longLongInteger);
  printf("%d\n", integer);
  printf("%ld\n", longInteger);
  printf("%hd\n", shortInteger);
  printf("%lld\n", longLongInteger);
  return 0;
}
