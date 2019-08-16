#include <stdio.h>
#include <assert.h>
int main(void)
{
  FILE *fp = fopen("file", "w");
  assert(fp != NULL);
  for (int i = 0; i < 10; i++)
    fputc('1', fp);
  fclose(fp);

  fp = fopen("file", "r+");
  assert(fp != NULL);
  for (int i = 0; i < 5; i++)
    fputc('2', fp);
  fclose(fp);

  fp = fopen("file", "r");
  assert(fp != NULL);
  int c;
  while ((c = fgetc(fp)) != EOF)
    fputc(c, stdout);
  fclose(fp);
  return 0;
}
