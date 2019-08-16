#include <stdio.h>
#include <stdbool.h>

#define EQL 5
#define NOTEQL 6
#define SMALLER 7
#define LARGER 8
#define SMALLEREQL 9
#define LARGEREQL 10

bool compare(int operand1, int operand2,
	     int operator)
{
  switch (operator) {
  case EQL:
    return (operand1 == operand2);
  case NOTEQL:
    return (operand1 != operand2);
  case SMALLER:
    return (operand1 < operand2);
  case LARGER:
    return (operand1 > operand2);
  case SMALLEREQL:
    return (operand1 <= operand2);
  case LARGEREQL:
    return (operand1 >= operand2);
  default:
    printf("invalid comp %d\n", operator);
    return 0;
  }
}

int main()
{
  int a, b, c;
  while (scanf("%d%d%d", &a, &b, &c) != EOF)
    printf("%d\n", compare(a, b, c));
  return 0;
}
