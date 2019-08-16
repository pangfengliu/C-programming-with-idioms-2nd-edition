#include <stdio.h>
#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3
#define MOD 4
main()
{
  int a, b, c, d;
  scanf("%d%d%d", &a, &b, &c);
  switch (c) {
  case ADD:
    d = a + b;    break;
  case SUB:
    d = a - b;    break;
  case MUL:
    d = a * b;    break;
  case DIV:
    d = a / b;    break;
  case MOD:
    d = a % b;
    break;
  default:
    printf("invalid c %d\n", c);
    d = 0;
  }
  printf("%d\n", d);
}

