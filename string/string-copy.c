#include <stdio.h>
#include <string.h>
#define STRINGLEN 80
int main(void)
{
  char source[STRINGLEN];
  char destination[STRINGLEN];
  scanf("%s%s", source, destination);
  printf("%s\n", destination);
  strcpy(destination, source);
  printf("%s\n", destination);
  return 0;
}
