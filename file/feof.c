#include <stdio.h>
#include <assert.h>
int main(void)
{
  FILE *fp = fopen("file", "w");
  assert(fp != NULL);
  for (int i = 0; i < 3; i++)
    fputc('1', fp);
  fclose(fp);
  fp = fopen("file", "r");
  assert(fp != NULL);
  int c = fgetc(fp);
  while (!feof(fp)) {
    putchar(c);
    c = fgetc(fp);
  }
  fclose(fp);
  return 0;
}
