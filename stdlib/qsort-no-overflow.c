/* qsort example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort */

int values[] = {2147483637, -2147483648,
		100, 90, 20, 25 };

int compare (const void * a, const void * b)
{
  int avalue = *(int*)a;
  int bvalue = *(int*)b;
  if (avalue > bvalue)
    return 1;
  else if (avalue < bvalue)
    return -1;
  return 0;
}

int main ()
{
  int n;
  qsort (values, 6, sizeof(int), compare);
  for (n=0; n<6; n++)
     printf ("%d ",values[n]);
  return 0;
}

