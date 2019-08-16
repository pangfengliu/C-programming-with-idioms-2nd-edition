#include <stdio.h>
#include <string.h>
#define STRINGLEN 80
int main(void)
{
  char source[STRINGLEN];
  char destination[STRINGLEN];

  scanf("%s", source);
  scanf("%s", destination);
  printf("%s\n", destination);
  strcat(destination, source);
  printf("%s\n", destination);
  return 0;
}
