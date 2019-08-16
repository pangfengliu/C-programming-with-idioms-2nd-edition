#include <stdio.h>
#include <stdlib.h>

#define STRINGLEN 80

int main(void)
{
  char string[STRINGLEN];
  scanf("%s", string);
  printf("atoi(string) = %d\n", atoi(string));
  scanf("%s", string);
  printf("atol(string) = %ld\n", atol(string));
  scanf("%s", string);
  printf("atof(string) = %f\n", atof(string));
  char *buffer = "123 abc";
  char *ptr;
  printf("123 in base 10 is %ld\n",
	 strtol(buffer, &ptr, 10));
  printf("abc in base 20 is %ld\n",
	 strtol(ptr, NULL, 20));
  return 0;
}
