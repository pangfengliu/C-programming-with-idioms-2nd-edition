#include <stdio.h>

main()
{
  int i, j;
  int r, c;
  int m[100][100];
  int max;

  scanf("%d%d", &r, &c);
  for (i = 0; i < r; i++)
    for (j = 0; j < c; j++)
      scanf("%d", &(m[i][j]));

  for (i = 0; i < r; i++) 
    for (j = 0; j < c; j++) {
      max = 1;
      if (i + 1 < r && m[i][j] <= m[i + 1][j]) 
	max = 0;
      if (i - 1 >= 0 && m[i][j] <= m[i - 1][j])
	max = 0;
      if (j + 1 < c && m[i][j] <= m[i][j + 1])
	max = 0;
      if (j - 1 >= 0 && m[i][j] <= m[i][j - 1])
	max = 0;
      if (max == 1)
	printf("%d\n", m[i][j]);
    }
}
