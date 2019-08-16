/* start */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack-list.h"
void initStack(Stack *s)
{
  s->top = NULL;
}
bool stackFull(Stack *s)
{
  return(0);
}
bool stackEmpty(Stack *s)
{
  return(s->top == NULL);
}
/* push */
void pushStack(Stack *s, char i)
{
  ListNode *current = 
    (ListNode *)malloc(sizeof(ListNode));
  assert(current != NULL);
  current->data = i;
  current->next = s->top;
  s->top = current;
}
char popStack(Stack *s)
{
  if (stackEmpty(s)) {
    printf("stack is empty\n");
    return(-1);
  }
  ListNode *current = s->top;
  s->top = s->top->next;
  char c = current->data;
  free(current);
  return(c);
}
/* end */
