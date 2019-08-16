#include <stdio.h>
#include "stack-define-type.h"
void initStack(Stack *s)
{
  s->top = 0;
}
int stackFull(Stack *s)
{
  return(s->top >= STACKSIZE);
}
int stackEmpty(Stack *s)
{
  return(s->top <= 0);
}
void pushStack(Stack *s, Data i)
{
  if (stackFull(s)) {
    printf("stack is full\n");
    return;
  }
  s->elements[s->top] = i;
  s->top++;
}
Data popStack(Stack *s)
{
  if (stackEmpty(s)) {
    printf("stack is empty\n");
    return(-1);
  }
  s->top--;
  return(s->elements[s->top]);
}
