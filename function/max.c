int max(int array[4][4])
{
  int i;
  int j;
  int max = array[0][0];

  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      if (array[i][j] > max)
	max = array[i][j];

  return max;
}
