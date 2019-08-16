/* basic */
#include <stdio.h>
#include "stack.h"
void initStack(Stack *s)
{
  s->top = 0;
}
bool stackFull(Stack *s)
{
  return(s->top >= STACKSIZE);
}
bool stackEmpty(Stack *s)
{
  return(s->top <= 0);
}
/* pushpop */
void pushStack(Stack *s, char i)
{
  if (stackFull(s)) {
    printf("stack is full\n");
    return;
  }
  s->elements[s->top] = i;
  s->top++;
}
int popStack(Stack *s)
{
  if (stackEmpty(s)) {
    printf("stack is empty\n");
    return(-1);
  }
  s->top--;
  return(s->elements[s->top]);
}
/* end */
