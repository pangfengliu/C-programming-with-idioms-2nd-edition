int f(int x, int y)
{
  return 4 * x - 6 * y;
}

int eval_f(int *iptr[], int n, int *index)
{
  int max = f(iptr[0][0], iptr[0][1]);
  *index = 0;
  int v;

  for (int i = 1; i < n; i++) {
    v =  f(iptr[i][0], iptr[i][1]);
    if (v >= max) {
      max = v;
      *index = i;
    }
  }
  return max;
}
