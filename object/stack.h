#include <stdbool.h>

#define STACKSIZE 100
struct stack {
  int top;
  char elements[STACKSIZE];
};
typedef struct stack Stack;

void initStack(Stack *s);
bool stackFull(Stack *s);
bool stackEmpty(Stack *s);
void pushStack(Stack *s, char c);
int popStack(Stack *s);

