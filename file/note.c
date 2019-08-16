#include <stdio.h>
#include <math.h>

int main()
{
  int p, inc, pitch;
  double frequency[130];
  int offset[] = {0, 0, 2, 4, 5, 7, 9, 11}; 

  for (p = 0; p < 130; p++) {
    frequency[p] = 440.0 * pow(2.0, (p - 69) / 12.0);
#ifdef PRINT
    printf("frequency = %f\n", frequency[p]);
#endif
  }

  while (scanf("%d", &pitch) != EOF) {
    inc = 0;
    if (pitch > 7)
      inc = 12 + offset[pitch - 7];
    else
      inc = offset[pitch];
    printf("%lf\n", frequency[58 + inc]);
  }
  return 0;  
}
