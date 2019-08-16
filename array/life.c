#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define MAXSIZE 100
main()
{
  int n, k;
  scanf("%d%d", &n, &k);
  assert(n >= 1 && n <= 100 && k > 0);

  int from = 0, to = 1;
  bool life[2][MAXSIZE][MAXSIZE];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      int temp;
      scanf("%d", &temp);
      life[from][i][j] = (temp == 1);
    }

  for (int iter = 0; iter < k ; iter++) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
	int neighbor = 0;
	for (int dx = -1; dx <= 1; dx++)
	  for (int dy = -1; dy <= 1; dy++)
	    if (!(dx == 0 && dy == 0)) {
	      int x = i + dx;
	      int y = j + dy;
	      if (x >= 0 && x < n && y >= 0
		  && y < n && life[from][x][y])
		neighbor++;
	    }
	if (life[from][i][j])
	  life[to][i][j] =
	    (neighbor == 2 || neighbor == 3);
	else       /* life[i][j] == false */
	  life[to][i][j] = (neighbor == 3);
      }
      from = (from == 1)? 0:1;
      to = (to == 1)? 0:1;
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (j == n - 1)
	printf("%d\n", life[from][i][j]);
      else
	printf("%d ", life[from][i][j]);
    }
}
