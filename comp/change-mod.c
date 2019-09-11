#include <stdio.h>
main()
{
  int change;
  scanf("%d", &change);
  int fifty = change / 50;
  change = change % 50;
  int ten = change / 10;
  change = change % 10;
  int five = change / 5;
  int one = change % 5;
  printf("%d\n", fifty); 
  printf("%d\n", ten); 
  printf("%d\n", five);
  printf("%d\n", one);
}
