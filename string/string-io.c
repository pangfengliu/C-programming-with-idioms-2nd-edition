#include <stdio.h>
#define STRINGLEN 10
int main(void)
{
  char string[STRINGLEN];

  while (scanf("%s", string) != EOF) {
    printf("%s\n", string);
    for (int i = 0; i < STRINGLEN && 
	   string[i] != '\0'; i++)
      printf("%c ", string[i]);
    printf("\n");
  }
}
