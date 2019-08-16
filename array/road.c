#include <stdio.h>

int main()
{
  int i, j, n, m, road[100][100];
  int intersection = 0;
  int T_junction = 0;
  int turn = 0;
  int dead_end = 0;
  int x, y, r;

  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      scanf("%d", &(road[i][j]));
  
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      if (road[i][j] == 1) {
	r = 0; x = 0; y = 0;
	if (i + 1 < n && road[i + 1][j] == 1) {
	  r++; x++;
	}
	if (i - 1 >= 0 && road[i - 1][j] == 1) {
	  r++; x++;
	}
	if (j + 1 < m && road[i][j + 1] == 1) {
	  r++; y++;
	}
	if (j - 1 >= 0 && road[i][j - 1] == 1) {
	  r++; y++;
	}
	switch (r) {
	case 1:
	  dead_end++;
	  break;
	case 2:
	  if (x == y) // both are 1
	    turn++;
	  break;
	case 3:
	  T_junction++;
	  break;
	case 4:
	  intersection++;
	  break;
	}
      }
    }
  printf("%d\n", intersection);
  printf("%d\n", T_junction);
  printf("%d\n", turn);
  printf("%d\n", dead_end);
  return 0;
}
