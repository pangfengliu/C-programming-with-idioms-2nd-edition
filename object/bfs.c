#include <stdio.h>
#include "queue.h"

#define N 128

int main(void)
{
  int adjacent[N][N];
  int distance[N];
  Queue cities;
  Queue *q = &cities;
  int i, j, n, m, a, b;
  int city;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    distance[i] = n + 1;
    for (j = 0; j < n; j++)
      adjacent[i][j] = 0;
  }
  distance[0] = 0;

  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%d%d", &a, &b);
    adjacent[a][b] = adjacent[b][a] = 1;
  }

  init(q);
  enqueue(q, 0);
  while (!empty(q)) {
    city = dequeue(q);
    for (i = 1; i < n; i++)
      if (adjacent[city][i] == 1)
	if (distance[i] == n + 1) { /* not ye visited */
	  distance[i] = distance[city] + 1;
	  enqueue(q, i);
	}
  }
  for (i = 1; i < n; i++) 
    if (distance[i] == n + 1)
      printf("infinity\n");
    else
      printf("%d\n", distance[i]);

  return 0;
}
