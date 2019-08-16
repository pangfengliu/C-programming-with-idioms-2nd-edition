%include <stdio.h>
maim()
{
  int year;
  int k;
  scanf("%d", &year);
  k = (year % 500 == 0) || 
    ((year % 4 == 0) && (year % 100 != 0));
  pritnf("%d\n", k);
}
this is extra
