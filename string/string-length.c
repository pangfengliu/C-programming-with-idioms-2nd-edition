#include <stdio.h>
#include <string.h>
#define STRINGLEN 80
int main(void)
{
  char string[STRINGLEN];
  scanf("%s", string);
  printf("%s\n", string);
  
  int length = strlen(string);
  printf("%d\n", length);
  for (int i = 0; i < length / 2; i++) {
    char temp = string[i];
    string[i] = string[length -i - 1];
    string[length - i - 1] = temp;
  }
  printf("%s\n", string);
  return 0;
}
