#include <stdio.h>
#include <string.h>
#define STRINGLEN 80
int main(void)
{
  char string[STRINGLEN];
  char *ptr = string;;
  scanf("%s", ptr);
  printf("%s\n", ptr);
  for (int i = 0; i < strlen(ptr); i++)
    printf("%c ", ptr[i]);
  return 0;
}


