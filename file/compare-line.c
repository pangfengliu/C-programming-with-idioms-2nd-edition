#include <stdio.h>
#include <assert.h>

#define N 80

int main(void)
{
  char filename[2][N];
  FILE *fp[2];
  char line[2][N];
  char *c[2];
  int line_num = 0;
  int i;
  int diff = 0;

  for (i = 0; i < 2; i++) {
    scanf("%s", filename[i]);
    fp[i] = fopen(filename[i], "rt");
  }
  assert(fp[0] != NULL && fp[1] != NULL);

  for (i = 0; i < 2; i++)
    c[i] = fgets(line[i], N, fp[i]);

  while (c[0] != NULL && c[1] != NULL) {
    if (strcmp(line[0], line[1]) != 0)
      printf("%d\n", line_num);
    line_num++;
    for (i = 0; i < 2; i++)
      c[i] = fgets(line[i], N, fp[i]);
  }

  diff = 1;			/* we have one byte diff already */
  if (c[0] == NULL) {
    if (c[1] != NULL) {
      while (fgets(line[1], N, fp[1]) != NULL)
	diff++;
      printf("%s %d", filename[1], diff);
    }
  } else {			/* c[0] != NULL */
    while (fgets(line[0], N, fp[0]) != NULL)
      diff++;
    printf("%s %d", filename[0], diff);
  }
  return 0;
}
