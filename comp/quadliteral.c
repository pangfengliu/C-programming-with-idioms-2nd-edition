#include <stdio.h>

#define linearFunction(a, b, c, d) \
  (-a * (d - b)) - (-b * (c - a))
  
int main()
{
  int a, b, c, d, e, f, g, h;
  int abcdSign;   
  int ghefSign;
  int abghSign;
  int cdefSign;

  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);
  scanf("%d", &e);
  scanf("%d", &f);
  scanf("%d", &g);
  scanf("%d", &h);

  abcdSign = linearFunction(a, b, c, d);
  ghefSign = linearFunction(g, h, e, f);
  abghSign = linearFunction(a, b, g, h);
  cdefSign = linearFunction(c, d, e, f);
  printf("%d %d %d %d\n", abcdSign, ghefSign, abghSign, cdefSign);

  printf("%d\n", abcdSign * ghefSign < 0 && abghSign * cdefSign < 0);
}
