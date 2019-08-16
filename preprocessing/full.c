#include "stack-define.h"
int stack_full(Stack *s)
{
  return(s->top >= STACKSIZE);
}

