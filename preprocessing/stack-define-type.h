#include <stdbool.h>
#define STACKSIZE 100
#define Data int
struct stack {
  int top;
  Data elements[STACKSIZE];
};
typedef struct stack Stack;

void initStack(Stack *s);
bool stackFull(Stack *s);
bool stackEmpty(Stack *s);
void pushStack(Stack *s, Data data);
Data popStack(Stack *s);


