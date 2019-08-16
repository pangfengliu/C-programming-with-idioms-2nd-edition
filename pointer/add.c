#include <stdio.h>

int add_n(int *iptr, int n)
{
  if (iptr == NULL)
    return 0;

  *iptr += n;
  return (*iptr);
}
