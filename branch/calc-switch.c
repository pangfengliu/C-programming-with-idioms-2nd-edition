#include <stdio.h>

main()
{
  int a, b, c, d;
  scanf("%d%d%d", &a, &b, &c);
  switch (c) {
  case 0:
    d = a + b;    break;
  case 1:
    d = a - b;    break;
  case 2:
    d = a * b;    break;
  case 3:
    d = a / b;    break;
  case 4:
    d = a % b;    break;
  default:
    printf("invalid c %d\n", c);
    d = 0;
  }
  printf("%d\n", d);
}

