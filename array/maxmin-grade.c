#include <stdio.h>

main()
{
  int s, c;
  int i, j, max, min;
  int grade[10][10];

  scanf("%d%d", &s, &c);
  for (i = 0; i < s; i++)
    for (j = 0; j < c; j++)
      scanf("%d", &(grade[i][j]));

  for (i = 0; i < s; i++) {
    max = min = grade[i][0];
    for (j = 1; j < c; j++) {
      if (grade[i][j] > max)
	max = grade[i][j];
      if (grade[i][j] < min)
	min = grade[i][j];
    }
    printf("%d %d\n", max, min);
  }

  for (j = 0; j < c; j++) {
    max = min = grade[0][i];
    for (i = 1; i < s; i++) {
      if (grade[i][j] > max)
	max = grade[i][j];
      if (grade[i][j] < min)
	min = grade[i][j];
    }
    printf("%d %d\n", max, min);
  }
}
