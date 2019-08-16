#include <stdio.h>
#define STRINGLEN 80
int mystrlen(char *string)
{
  int i = 0;
  while (i < STRINGLEN && string[i] != '\0')
    i++;
  return i;
}
int main(void)
{
  char string[STRINGLEN];
  scanf("%s", string);
  printf("%s\n", string);
  int length = mystrlen(string);
  printf("%d\n", length);
  return 0;
}
