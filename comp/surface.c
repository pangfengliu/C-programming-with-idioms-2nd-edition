#include <stdio.h>

main()
{
  int a, b, c;
  int surface, volume;

  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  surface = 2 * (a * b + b * c + a * c);
  volume = a * b * c;

  printf("%d\n", surface);
  printf("%d\n", volume);
}
