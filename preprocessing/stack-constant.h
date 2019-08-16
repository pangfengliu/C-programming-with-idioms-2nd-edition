#include <stdbool.h>
struct stack {
  int top;
  char elements[100];
};
typedef struct stack Stack;

void initStack(Stack *s);
bool stackFull(Stack *s);
bool stackEmpty(Stack *s);
void pushStack(Stack *s, char data);
int popStack(Stack *s);

