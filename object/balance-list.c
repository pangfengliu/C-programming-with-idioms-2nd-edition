/* main */
#include <stdio.h>
#include "stack-list.h"
#define STRINGLEN 128
int main(void)
{
  char string[STRINGLEN];
  Stack stack;
  bool balanced = true;
  scanf("%s", string);
  initStack(&stack);
  /* loop */
  for (int i = 0; string[i] != '\0' && balanced;
       i++) 
    switch (string[i]) {
    case '(': case '[': case '{':
      pushStack(&stack, string[i]); break;
    case ')': 
      if (popStack(&stack) != '(')
	balanced = false;
      break;
    case ']': 
      if (popStack(&stack) != '[')
	balanced = false;
      break;
    case '}':
      if (popStack(&stack) != '{')
	balanced = false;
      break;
    default:
      balanced = false;
    }
  /* checkempty */
  if (!balanced || !stackEmpty(&stack))
    printf("not balanced\n");
  else
    printf("balanced\n");
  return 0;
}
/* end */
