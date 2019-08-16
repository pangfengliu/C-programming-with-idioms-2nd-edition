#include <stdio.h>
#include "stack.h"
#define STRINGLEN 128
int main(void)
{
  char string[STRINGLEN];
  Stack stack;
  bool balanced = true;
  scanf("%s", string);
  initStack(&stack);
  for (int i = 0; string[i] != '\0' && balanced;
       i++) 
    switch (string[i]) {
    case '(': case '[': case '{':
      pushStack(&stack, string[i]);
      break;
    case ')': balanced =
	(popStack(&stack) == '(');
      break;
    case ']': balanced =
	(popStack(&stack) == '[');
      break;
    case '}': balanced =
	(popStack(&stack) == '{');
      break;
    default: balanced = false;
    }
  if (balanced && stackEmpty(&stack))
    printf("balanced\n");
  return 0;
}
