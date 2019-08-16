#define init_2d(array, n, m) \
  { int i, j; \
  for (i = 0; i < n; i++) \
    for (j = 0; j < m; j++)			\
      array[i][j] = 0; \
  }
