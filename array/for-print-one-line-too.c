#include <stdio.h>
main()
{
  int i;
  int start1;
  int end1;
  int start2;
  int end2;
  scanf("%d", &start1);
  scanf("%d", &end1);
  scanf("%d", &start2);
  scanf("%d", &end2);
  for (i = start1; i <= end1; i++)
    printf("%d ", i);
  for (i = start2; i <= end2; i++)
    printf("%d ", i);
}
