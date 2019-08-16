#include <stdio.h>
#include <assert.h>
main()
{
  int start, end;
  scanf("%d%d", &start, &end);
  assert(start <= end);
  for (int i = start; i <= end; i++)
    printf("%d ", i);
}
