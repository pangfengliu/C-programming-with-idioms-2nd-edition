#include <stdio.h>
#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3
#define MOD 4

int arithmetic(int operand1, int operand2, 
	       int operator)
{
  switch (operator) {
  case ADD:
    return (operand1 + operand2);
  case SUB:
    return (operand1 - operand2);
  case MUL:
    return (operand1 * operand2);
  case DIV:
    return (operand1 / operand2);
  case MOD:
    return (operand1 % operand2);
  default:
    printf("invalid comp %d\n", operator);
    return 0;
  }
}

int main()
{
  int a, b, c;
  while (scanf("%d%d%d", &a, &b, &c) != EOF)
    printf("%d\n", arithmetic(a, b, c));
  return 0;
}
