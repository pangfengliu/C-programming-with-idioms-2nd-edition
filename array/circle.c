#include <stdio.h>

main()
{
  int n;
  scanf("%d", &n);
  int array[n][n];
  for (int r = 0; r < n; r++)
    for (int c = 0; c < n; c++)
      scanf("%d", &(array[r][c]));

  int dr[4] = {0, -1, 0, 1};
  int dc[4] = {-1, 0, 1, 0};
  int row = n / 2;
  int col = n / 2;
  int direction = 0;

  printf("%d\n", array[row][col]);
  for (int dist = 1; dist < n; dist++)
    for (int step = 0;
	 step < ((dist == n - 1)? 3 : 2);
	 step++) {
      for (int i = 0; i < dist; i++) {
	row += dr[direction];
	col += dc[direction];
	printf("%d\n", array[row][col]);
      }
      direction = ((direction + 1) % 4);
    }
}
