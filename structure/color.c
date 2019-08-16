#include <stdio.h>
#include "color.h"

void initColor(Color *c, int r, int g, int b)
{
  c->r = r;
  c->g = g;
  c->b = b;
}

void printColor(Color *c)
{
  printf("(%d, %d, %d) %f\n", c->r, c->g, c->b, brightness(c));
  return;
}

Color averageColor(Color c[], int n)
{
  int i;
  int rsum = 0;
  int gsum = 0;
  int bsum = 0;
  Color average;

  for (i = 0; i < n; i++) {
    rsum += c[i].r;
    gsum += c[i].g;
    bsum += c[i].b;
  }
  
  average.r = rsum / n;
  average.g = gsum / n;
  average.b = bsum / n;

  return average;
}

double brightness(Color *c)
{
  return((double)(c->r + c->g + c->b) / 3.0);
}
