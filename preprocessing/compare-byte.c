#include <stdio.h>
#include <assert.h>

#define N 80

int main(void)
{
  char filename[2][N];
  FILE *fp[2];
  int c[2];
  int offset = 0;
  int i;
  int diff = 0;

  for (i = 0; i < 2; i++) {
    scanf("%s", filename[i]);
    fp[i] = fopen(filename[i], "rb");
  }
  assert(fp[0] != NULL && fp[1] != NULL);

  for (i = 0; i < 2; i++)
    c[i] = fgetc(fp[i]);

  while (c[0] != EOF && c[1] != EOF) {
    if (c[0] != c[1]) {
#ifdef VERBOSE
      printf("offset %04d: %2x != %2x\n", offset, c[0], c[1]);
#else
      printf("%04d\n", offset);
#endif
    }
    offset++;
    for (i = 0; i < 2; i++)
      c[i] = fgetc(fp[i]);
  }

  diff = 1;			/* we have one byte diff already */
  if (c[0] == EOF) {
    if (c[1] != EOF) {
      while (c[1] = fgetc(fp[1]) != EOF)
	diff++;
      printf("%s %d", filename[1], diff);
    }
  } else {			/* c[0] != EOF */
    while (c[0] = fgetc(fp[0]) != EOF)
	diff++;
    printf("%s %d", filename[0], diff);
  }
  return 0;
}
