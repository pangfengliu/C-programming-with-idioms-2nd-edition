#define STACKSIZE 100
typedef int Data;
struct stack {
  int top;
  Data elements[STACKSIZE];
};
typedef struct stack Stack;
void init_stack(Stack *s);
int stack_full(Stack *s);
int stack_empty(Stack *s);
void push_stack(Stack *s, Data data);
Data pop_stack(Stack *s);

