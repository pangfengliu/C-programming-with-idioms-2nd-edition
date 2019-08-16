#include <stdio.h>
#include <string.h>
#define STRINGLEN 80
int main(void)
{
  char str1[STRINGLEN] = "programming";
  char str2[] = "programming";
  char *str3 = "programming";
  printf("sizeof(str1) = %ld\n", sizeof(str1));
  printf("sizeof(str2) = %ld\n", sizeof(str2));
  printf("sizeof(str3) = %ld\n", sizeof(str3));
  return 0;
}


