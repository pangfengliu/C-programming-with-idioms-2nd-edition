#include <stdio.h>
#include <string.h>
#define STRINGLEN 80
int main(void)
{
  char str1[STRINGLEN] = "programming";
  char str2[] = "programming";
  char *str3 = "programming";
  printf("strlen(str1) = %ld\n", strlen(str1));
  printf("strlen(str2) = %ld\n", strlen(str2));
  printf("strlen(str3) = %ld\n", strlen(str3));
  return 0;
}


