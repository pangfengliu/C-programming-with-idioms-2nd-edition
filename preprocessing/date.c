#include <stdio.h>

int main(void)
{
  int y, m, d;
  scanf("%d%d%d", &y, &m, &d);
#ifdef MMDDYY
  printf("%02d/%02d/%4d", m, d, y);
#endif
#ifdef DDMMYY
  printf("%02d/%02d/%4d", d, m, y);
#endif
#ifdef YYMMDD
  printf("%04d/%02d/%02d", y, m, d);
#endif
  return 0;
}
