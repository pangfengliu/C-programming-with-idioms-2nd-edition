#include <stdio.h>
#include <string.h>
#include "stack.h"
#define STRINGLEN 128
int main(void)
{
  char string[STRINGLEN];
  scanf("%s", string);

  int length = strlen(string);
  int half = length / 2;

  Stack stack;
  initStack(&stack);

  for (int i = 0; i < half; i++) 
    pushStack(&stack, string[i]);
  for (int i = length - half; i < length; i++)
    if (string[i] != popStack(&stack)) {
      printf("not a palindrome\n");
      return 0;
    }
  printf("palindrome\n");
  return 0;
}
