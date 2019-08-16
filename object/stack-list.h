#include <stdbool.h>

struct listnode {
  char data;
  struct listnode *next;
};
  
typedef struct listnode ListNode;

struct stack {
  ListNode *top;
};
typedef struct stack Stack;

void initStack(Stack *s);
bool stackFull(Stack *s);
bool stackEmpty(Stack *s);
void pushStack(Stack *s, char data);
char popStack(Stack *s);

