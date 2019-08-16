int max(int *iptr[], int n)
{
  int maxv = *(iptr[0]);

  for (int i = 1; i < n; i++)
    if (*(iptr[i]) > maxv)
      maxv = *(iptr[i]);

  return maxv;
}
