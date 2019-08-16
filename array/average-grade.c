#include <stdio.h>

main()
{
  int s, c;
  int i, j, sum;
  int grade[10][10];

  scanf("%d%d", &s, &c);
  for (i = 0; i < s; i++)
    for (j = 0; j < c; j++)
      scanf("%d", &(grade[i][j]));

  for (i = 0; i < s; i++) {
    sum = 0;
    for (j = 0; j < c; j++)
      sum += grade[i][j]; 
    printf("%d\n", sum / c);
  }

  for (j = 0; j < c; j++) {
    sum = 0;
    for (i = 0; i < s; i++) 
      sum += grade[i][j]; 
    printf("%d\n", sum / s);
  }
}
